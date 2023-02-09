/*******************************************************************************

  Copyright (C) 2011 Andrew Gilbert

  This file is part of IQmol, a free molecular visualization program. See
  <http://iqmol.org> for more details.

  IQmol is free software: you can redistribute it and/or modify it under the
  terms of the GNU General Public License as published by the Free Software
  Foundation, either version 3 of the License, or (at your option) any later
  version.

  IQmol is distributed in the hope that it will be useful, but WITHOUT ANY
  WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
  FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
  details.

  You should have received a copy of the GNU General Public License along
  with IQmol.  If not, see <http://www.gnu.org/licenses/>.

********************************************************************************/

#include "MainWindow.h"
#include "OptionDatabase.h"
#include "EditOptionDialog.h"
#include "QMsgBox.h"
#include "Option.h"
#include <QFileDialog>
#include <QHeaderView>

#include <QtDebug>


namespace QCDBEdit {

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent)
{
   m_mainWindow.setupUi(this);
   m_mainWindow.remTableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Interactive);
   m_mainWindow.remTableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
   createMenus();

   QTableWidget* table(m_mainWindow.remTableWidget);

   table->setColumnWidth(0, 250);
   table->setColumnWidth(1, 100);
   table->setColumnWidth(2, 100);
   table->setColumnWidth(3, 100);

   connect(table, SIGNAL(cellDoubleClicked(int, int)),
      this, SLOT(itemDoubleClicked(int, int)));
}


void MainWindow::open(QString const& fileName)
{
   m_database = new OptionDatabase(fileName);  

   if (!m_database->loaded()) {
      QString msg("Attempt to open database file " + fileName);
      msg += " failed";
      QMsgBox::information(this, "QCDBEdit", msg);
      return;
   }

   Option option;
   QStringList allOptions(m_database->all());
   QStringList::iterator iter;
   QTableWidget* table(m_mainWindow.remTableWidget);

   for (iter = allOptions.begin(); iter != allOptions.end(); ++iter) {
       if (m_database->get(*iter, option)) addToTable(option);
   }

   table->setSortingEnabled(true);
   table->sortItems(0);
}


void MainWindow::addToTable(Option const& option)
{
   QTableWidget* table(m_mainWindow.remTableWidget);
   QTableWidgetItem* item;

   int row(table->rowCount());
   table->setRowCount(row+1);
   table->setSortingEnabled(false);

   item = new QTableWidgetItem(option.getName());
   table->setItem(row, 0, item);
   item = new QTableWidgetItem(option.getDefaultValue());
   item->setTextAlignment(Qt::AlignRight|Qt::AlignVCenter);
   table->setItem(row, 1, item);
   item = new QTableWidgetItem(option.getOptionString());
   item->setTextAlignment(Qt::AlignRight|Qt::AlignVCenter);
   table->setItem(row, 2, item);
   item = new QTableWidgetItem(option.getTypeAsString());
   item->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
   table->setItem(row, 3, item);
   item = new QTableWidgetItem(option.getImplAsString());
   table->setItem(row, 4, item);

   table->setSortingEnabled(true);
}


void MainWindow::insertIntoTable(int const row, Option const& option)
{
   QTableWidget* table(m_mainWindow.remTableWidget);
   table->setSortingEnabled(false);
   table->item(row,0)->setText(option.getName());
   table->item(row,1)->setText(option.getDefaultValue());
   table->item(row,2)->setText(option.getOptionString());
   table->item(row,3)->setText(option.getTypeAsString());
   table->item(row,4)->setText(option.getImplAsString());
   table->setSortingEnabled(true);
}


QTableWidgetItem* MainWindow::findOptionInTable(QString const& name)
{
   QTableWidget* table(m_mainWindow.remTableWidget);
   QList<QTableWidgetItem*> matchingItems(table->findItems(name, Qt::MatchExactly));
   QTableWidgetItem* item(0);

   QList<QTableWidgetItem*>::iterator iter;
   for (iter = matchingItems.begin(); iter != matchingItems.end(); ++iter) {
       if ((*iter)->column() == 0) {
          item = (*iter);
          break;
       }
   }

   return item;
}


void MainWindow::itemDoubleClicked(int row, int)
{
   QString name(m_mainWindow.remTableWidget->item(row, 0)->text());
   Option* option;

   if (m_queuedChanges.contains(name)) {
      qDebug() << "Returning copy from queuedChanges" << name;
      option = new Option(*m_queuedChanges[name]);
   }else {
      qDebug() << "Returning copy from Database" << name;
      option = new Option();
      if (!m_database->get(name, *option)) {
         QMsgBox::warning(this, "QCDBEdit", "Could not find option in database");
         delete option;
         return;
      }
   }

   bool prompt(false);
   editOption(option, prompt);
}


void MainWindow::on_addOptionButton_clicked(bool)
{
   bool prompt(true);
   editOption(new Option(), prompt);
}


void MainWindow::editOption(Option* option, bool prompt)
{
   EditOptionDialog dialog(this, option);

   if (dialog.exec() == QDialog::Rejected) {
      delete option;
      return;
   }

   QString name(option->getName());
   QTableWidgetItem* item(findOptionInTable(name));

   if (item && prompt) {
      QString msg("An options of this name already exists. Overwrite?");
      if (QMsgBox::question(this, "QCDBEdit", msg) != QMessageBox::Ok) {
         delete option;
         return;
      }
   }

   if (item) {
      insertIntoTable(item->row(), *option);
   }else {
      addToTable(*option);
   }

   if (m_queuedChanges.contains(name)) {
      delete m_queuedChanges[name];
   }
   
   m_queuedChanges[name] = option;

   // Debug
   QMap<QString, Option*>::iterator iter;
   for (iter = m_queuedChanges.begin(); iter != m_queuedChanges.end(); ++iter) {
       qDebug() << "options queued" << iter.key();
   }
}


void MainWindow::on_editOptionButton_clicked(bool)
{
   QTableWidget* table(m_mainWindow.remTableWidget);
   int row(table->currentRow());
   if (row >= 0) itemDoubleClicked(row, 0);
}


void MainWindow::on_deleteOptionButton_clicked(bool)
{
   QTableWidget* table(m_mainWindow.remTableWidget);
   int row(table->currentRow());
   qDebug() <<"Deleting row" << row;
   if (row >= 0) deleteOption(table->item(row,0)->text());
}


void MainWindow::deleteOption(QString const& name)
{
   QTableWidgetItem* item(findOptionInTable(name));
   if (item) m_mainWindow.remTableWidget->removeRow(item->row());

   if (m_queuedChanges.contains(name)) {
      delete m_queuedChanges[name];
      m_queuedChanges.remove(name);
   }
   m_queuedDeletions.insert(name);
}


void MainWindow::commitChanges()
{
   bool prompt(false);
   QSet<QString>::iterator del;
   for (del = m_queuedDeletions.begin(); del != m_queuedDeletions.end(); ++del) {
       qDebug() << "Deleting" << *del << "from database";
       m_database->remove(*del, prompt);
   }
   m_queuedDeletions.clear();

   QMap<QString, Option*>::iterator iter;
   for (iter = m_queuedChanges.begin(); iter != m_queuedChanges.end(); ++iter) {
       qDebug() << "Commiting changes to option" << iter.key();
       m_database->insert(*(iter.value()), prompt);
       delete iter.value();
   }
   m_queuedChanges.clear();
}


void MainWindow::quit()
{
   if (!m_queuedChanges.isEmpty() || !m_queuedDeletions.isEmpty()) {
      QString msg("Commit changes to database?");
      if (QMsgBox::question(this, "QCDBEdit", msg) == QMessageBox::Ok) commitChanges();
   }

   QApplication::quit();
}


void MainWindow::createMenus()
{
   QAction* action;
   QString  name;
   QMenu*   menu;
  
   menu = menuBar()->addMenu("File");

      name = "Open";
      action = menu->addAction(name);
      connect(action, SIGNAL(triggered()), this, SLOT(openFile()));
      action->setShortcut(QKeySequence::Open);

      name = "Save";
      action = menu->addAction(name);
      connect(action, SIGNAL(triggered()), this, SLOT(commitChanges()));
      action->setShortcut(QKeySequence::Save);

      menu->addSeparator();

      name = "Quit";
      action = menu->addAction(name);
      connect(action, SIGNAL(triggered()), this, SLOT(quit()));
      action->setShortcut(Qt::CTRL + Qt::Key_Q);
}


void MainWindow::openFile()
{
   QString name(QFileDialog::getOpenFileName(this, tr("Open File")));
   if (!name.isEmpty()) open(name);
}

} // end namespace QCDBEdit
