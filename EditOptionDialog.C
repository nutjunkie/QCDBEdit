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

#include "EditOptionDialog.h"
#include "OptionNumberEditor.h"
#include "OptionListEditor.h"
#include "Option.h"
#include "QMsgBox.h"

#include <QtDebug>


namespace QCDBEdit {

EditOptionDialog::EditOptionDialog(QWidget* parent, Option* option) 
   : QDialog(parent), m_option(option)
{
   m_editOptionDialog.setupUi(this);
   loadOption(*m_option);
}


void EditOptionDialog::loadOption(Option const& option)
{
   m_editOptionDialog.nameLineEdit->setText(option.getName());
   m_editOptionDialog.dataTypeCombo->setCurrentIndex(option.getType());
   m_editOptionDialog.widgetCombo->setCurrentIndex(option.getImplementation());
   m_editOptionDialog.optionsCombo->addItems(option.getOptions());
   m_editOptionDialog.optionsCombo->setCurrentIndex(option.getDefaultIndex());
   m_editOptionDialog.documentationText->setHtml(option.getDescription());

   if (option.getType() == Option::Type_Logical) {
      m_editOptionDialog.editOptionsButton->setEnabled(false);
   }
}


bool EditOptionDialog::unloadOption(Option& option)
{
   QString name(m_editOptionDialog.nameLineEdit->text().toUpper().trimmed());
   if (name.isEmpty()) return false;
   name = name.replace(" ", "_");

   option.setName(name);
   option.setType(m_editOptionDialog.dataTypeCombo->currentIndex());
   option.setImplementation(m_editOptionDialog.widgetCombo->currentIndex());
   option.setDefault(m_editOptionDialog.optionsCombo->currentIndex());

   QStringList options;
   for (int i = 0; i < m_editOptionDialog.optionsCombo->count(); ++i) {
       options.append(m_editOptionDialog.optionsCombo->itemText(i));
   }
   option.setOptions(options);

   // toHtml protects the <> tags by turning them into &lt; and &gt;
   // so we need to undo this so that next time it displays correctly.
   QString tmp(m_editOptionDialog.documentationText->toHtml());
   tmp.replace(QString("&lt;"), QString("<"));
   tmp.replace(QString("&gt;"), QString(">"));
   tmp.replace(QString("&amp;"), QString("&"));
   option.setDescription(tmp);
   return true;
}


void EditOptionDialog::accept()
{
   close();
   if (unloadOption(*m_option)) {
      qDebug() << "sending accepted sign";
      done(QDialog::Accepted);   
   }else {
      done(QDialog::Rejected);   
   }
}


void EditOptionDialog::on_dataTypeCombo_currentIndexChanged(int type) 
{
   if (type == Option::Type_Logical) {
	  // make a back up of the current options in case the user want to undo
	  // this selection.
      m_backup.clear();
      for (int i = 0; i < m_editOptionDialog.optionsCombo->count(); ++i) {
          m_backup.append(m_editOptionDialog.optionsCombo->itemText(i));
      }

      m_backupIndex = m_editOptionDialog.optionsCombo->currentIndex();

      m_editOptionDialog.optionsCombo->clear();
      m_editOptionDialog.optionsCombo->addItem("FALSE");
      m_editOptionDialog.optionsCombo->addItem("TRUE");
      m_editOptionDialog.editOptionsButton->setEnabled(false);

   }else {
      if (m_backup.count() > 0) {
         m_editOptionDialog.optionsCombo->clear();
         m_editOptionDialog.optionsCombo->addItems(m_backup);
         m_editOptionDialog.optionsCombo->setCurrentIndex(m_backupIndex);
         m_backup.clear();
         m_backupIndex = 0;
      }
      m_editOptionDialog.editOptionsButton->setEnabled(true);
   }

   switch (type) {
      case Option::Type_Integer:
         m_editOptionDialog.widgetCombo->setCurrentIndex(Option::Impl_Spin);
         break;
      case Option::Type_Logical:
         m_editOptionDialog.widgetCombo->setCurrentIndex(Option::Impl_Check);
         break;
      case Option::Type_String:
         m_editOptionDialog.widgetCombo->setCurrentIndex(Option::Impl_Combo);
         break;
      case Option::Type_Real:
         m_editOptionDialog.widgetCombo->setCurrentIndex(Option::Impl_DSpin);
         break;
      case Option::Type_Array:
         m_editOptionDialog.widgetCombo->setCurrentIndex(Option::Impl_Text);
         break;
   }
}


void EditOptionDialog::on_editOptionsButton_clicked(bool)
{
   QStringList options;
   int n(m_editOptionDialog.optionsCombo->count());

   for (int i = 0; i < n; ++i) {
       options.append(m_editOptionDialog.optionsCombo->itemText(i));
   }

   QString defval;
   int defaultIndex(m_option->getDefaultIndex());
   if (0 <= defaultIndex && defaultIndex < options.size()) {
       defval = options[defaultIndex];
   }

   int impl(m_editOptionDialog.widgetCombo->currentIndex());
   QValidator* validator(0);
   QDialog* dialog;

   switch (impl) {
      case Option::Impl_Spin:
         validator = new QIntValidator(this);
         dialog = new OptionNumberEditor(this, options, validator);
         break;
      case Option::Impl_DSpin:
         validator = new QDoubleValidator(this);
         dialog = new OptionNumberEditor(this, options, validator);
         break;
      default:
         dialog = new OptionListEditor(this, options);
         break;
   }

   if (validator) delete validator;

   if (dialog->exec() == QDialog::Accepted) {
      m_editOptionDialog.optionsCombo->clear();
      m_editOptionDialog.optionsCombo->addItems(options);
      if (impl == Option::Impl_Spin || impl == Option::Impl_DSpin) {
         defaultIndex = 2;
      }else {
         defaultIndex = options.indexOf(defval);
      }
      if (defaultIndex < 0) defaultIndex = 0;
      m_editOptionDialog.optionsCombo->setCurrentIndex(defaultIndex);
   }

   delete dialog;
}


} // end namespace QCDBEdit
