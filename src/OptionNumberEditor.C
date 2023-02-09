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

#include "OptionNumberEditor.h"
#include <QValidator>


namespace QCDBEdit {


OptionNumberEditor::OptionNumberEditor(QWidget* parent, QStringList& values, 
   QValidator* validator) : QDialog(parent), m_values(values)
{
   m_optionNumberEditor.setupUi(this);
   while (m_values.size() < 4) m_values.append(QString::number(0));

   m_optionNumberEditor.minimumLineEdit->setText(m_values[0]);
   m_optionNumberEditor.minimumLineEdit->setValidator(validator);
   m_optionNumberEditor.maximumLineEdit->setText(m_values[1]);
   m_optionNumberEditor.maximumLineEdit->setValidator(validator);
   m_optionNumberEditor.defaultLineEdit->setText(m_values[2]);
   m_optionNumberEditor.defaultLineEdit->setValidator(validator);
   m_optionNumberEditor.stepSizeLineEdit->setText(m_values[3]);
   m_optionNumberEditor.stepSizeLineEdit->setValidator(validator);
}


void OptionNumberEditor::accept()
{
   m_values.clear();
   m_values.append(m_optionNumberEditor.minimumLineEdit->text());
   m_values.append(m_optionNumberEditor.maximumLineEdit->text());
   m_values.append(m_optionNumberEditor.defaultLineEdit->text());
   m_values.append(m_optionNumberEditor.stepSizeLineEdit->text());

   close();
   done(QDialog::Accepted);
}

} // end namespace QCDBEdit
