#ifndef QCDBEDIT_MAINWINDOW_H
#define QCDBEDIT_MAINWINDOW_H
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

#include "ui_MainWindow.h"
#include <QMap>
#include <QSet>


class QTableWidgetItem;

namespace QCDBEdit {

   class OptionDatabase;
   class Option;

   /// MainWindow is the top level window in QCDBEdit which displays a table of
   /// the options
   class MainWindow : public QMainWindow {

      Q_OBJECT

      public: 
         MainWindow(QWidget* parent = 0);
          void open(QString const& fileName);

      public Q_SLOTS:
         void quit();

      private Q_SLOTS:
         void openFile();

         /// Writes changes to options to the database.
         void commitChanges();

         void itemDoubleClicked(int, int);
         void on_addOptionButton_clicked(bool);
         void on_deleteOptionButton_clicked(bool);
         void on_editOptionButton_clicked(bool);

      private:
         void createMenus();

		 /// Adds an option to the table without checking for duplication.
         void addToTable(Option const&);

		 /// Inserts an Option into a given row in the table, overwriting any
		 /// existing data.  Note that it assumed that the row exists in the
		 /// table.
         void insertIntoTable(int const row, Option const& option);

		 /// Searches for the option name in the table and, if found, returns a
		 /// pointer to the item.  If the name does not exist, a null pointer is
		 /// returned.
         QTableWidgetItem* findOptionInTable(QString const& name);

		 /// Opens a EditOptionDialog to allow the user to edit an option.  If
		 /// the user accepts the changes then option is added to the table,
		 /// overwriting the option if it exists.  If prompt is true then the
		 /// user is prompted before overwriting.  Note that the option pointer
		 /// is added to the change queue if accepted and deleted if rejected.
         void editOption(Option* option, bool prompt);

         /// Adds the option name to the queue for deletion
         void deleteOption(QString const& name);

         Ui::MainWindow m_mainWindow;
         OptionDatabase* m_database;
         QMap<QString, Option*> m_queuedChanges;
         QSet<QString> m_queuedDeletions;
   };

} // end namespace QCDBEdit

#endif
