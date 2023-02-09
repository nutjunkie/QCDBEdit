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

#include "OptionListEditor.h"


namespace QCDBEdit {

OptionListEditor::OptionListEditor(QWidget* parent, QStringList& values) : QDialog(parent),
   m_values(values)
{
   m_optionListEditor.setupUi(this);
   m_optionListEditor.optionList->addItems(m_values);
}


void OptionListEditor::on_addButton_clicked(bool)
{
   QListWidgetItem* item = new QListWidgetItem(tr("New value"));
   item->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable | Qt::ItemIsEditable);
   int row = m_optionListEditor.optionList->currentRow();
   if (row < 0) row = m_optionListEditor.optionList->count();

   m_optionListEditor.optionList->insertItem(row+1,item);
   m_optionListEditor.optionList->setCurrentItem(item);
   m_optionListEditor.optionList->editItem(item);
}


void OptionListEditor::on_deleteButton_clicked(bool) {
   QList<QListWidgetItem*> items = m_optionListEditor.optionList->selectedItems();
   for (int i = 0; i < items.size(); ++i) {
      delete m_optionListEditor.optionList->takeItem(m_optionListEditor.optionList->row(items[i]));
   }
}


void OptionListEditor::on_upButton_clicked(bool) {
   int row(m_optionListEditor.optionList->currentRow());
   QListWidgetItem* item;

   if (row > 0) {
      item = m_optionListEditor.optionList->takeItem(row);
      m_optionListEditor.optionList->insertItem(row-1,item);
      m_optionListEditor.optionList->setCurrentItem(item);
   }
}


void OptionListEditor::on_downButton_clicked(bool) {
   int row(m_optionListEditor.optionList->currentRow());
   int max(m_optionListEditor.optionList->count());
   QListWidgetItem* item;

   if (row < max-1) {
      item = m_optionListEditor.optionList->takeItem(row);
      m_optionListEditor.optionList->insertItem(row+1,item);
      m_optionListEditor.optionList->setCurrentItem(item);
   }
}


void OptionListEditor::accept()
{
   // This is required to ensure no persistent editor is open.
   m_optionListEditor.optionList->setCurrentRow(-1);
   m_values.clear();

   for (int i = 0; i < m_optionListEditor.optionList->count(); ++i) {
       m_values.append(m_optionListEditor.optionList->item(i)->text());
   }

   close();
   done(QDialog::Accepted);
}


} // end namespace QCDBEdit
