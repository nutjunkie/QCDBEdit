#ifndef QCDBEDIT_OPTIONNUMBEREDITOR_H
#define QCDBEDIT_OPTIONNUMBEREDITOR_H
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

#include "ui_OptionNumberEditor.h"
#include <QStringList>


class QValidator;

namespace QCDBEdit {

   /// Provides a dialog for editing a numerical value including valid ranges,
   /// the step size and default value.
   class OptionNumberEditor : public QDialog {

      Q_OBJECT

      public: 
         OptionNumberEditor(QWidget* parent, QStringList& values, QValidator*);

      public Q_SLOTS:
         void accept();

      private:
         QStringList& m_values;
         Ui::OptionNumberEditor m_optionNumberEditor;
   };

} // end namespace QCDBEdit

#endif
