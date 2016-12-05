#ifndef QCDBEDIT_OPTIONLISTEDITOR_H
#define QCDBEDIT_OPTIONLISTEDITOR_H
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

#include "ui_OptionListEditor.h"
#include <QStringList>


class QValidator;

namespace QCDBEdit {

   /// Provides a dialog for editing a list of option values.
   class OptionListEditor : public QDialog {

      Q_OBJECT

      public: 
         OptionListEditor(QWidget* parent, QStringList& values);

      public Q_SLOTS:
         void accept();

      private Q_SLOTS:
         void on_addButton_clicked(bool);
         void on_deleteButton_clicked(bool);
         void on_upButton_clicked(bool);
         void on_downButton_clicked(bool);

      private:
         QStringList& m_values;
         Ui::OptionListEditor m_optionListEditor;
   };

} // end namespace QCDBEdit

#endif
