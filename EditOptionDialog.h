#ifndef QCDBEDIT_OPTIONDIALOG_H
#define QCDBEDIT_OPTIONDIALOG_H
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

#include "ui_EditOptionDialog.h"


namespace QCDBEdit {

   class Option;

   /// Provides a dialog for editing Option values.
   class EditOptionDialog : public QDialog {

      Q_OBJECT

      public: 
         EditOptionDialog(QWidget* parent, Option*);
         ~EditOptionDialog() { }

      public Q_SLOTS:
         void accept();

      private Q_SLOTS:
         void on_dataTypeCombo_currentIndexChanged(int type);
         void on_editOptionsButton_clicked(bool);

      private:
         void loadOption(Option const&);
         bool unloadOption(Option&);
         Option* m_option;
         Ui::OptionDialog m_editOptionDialog;
         QStringList m_backup;
         int m_backupIndex;
   };

} // end namespace QCDBEdit

#endif
