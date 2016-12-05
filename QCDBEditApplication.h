#ifndef QCDBEDIT_QCDBEDITAPPLICATION_H
#define QCDBEDIT_QCDBEDITAPPLICATION_H
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

#include <QApplication>
#include <QEvent>


class QStringList;

namespace QCDBEdit {

   class MainWindow;

   /// QApplication subclassed to handle QFileOpenEvents for Mac.
   class QCDBEditApplication : public QApplication {

      Q_OBJECT

      public:
         QCDBEditApplication(int &argc, char** argv);
         ~QCDBEditApplication();
         void queueOpenFiles(QStringList const& files);

      protected:
         bool event(QEvent*);

      private Q_SLOTS:
         void open(QString const& file);

      private:
         MainWindow* m_mainWindow;
   };


   /// Customzed QEvent that delays the opening of files until the event loop
   /// has started.  This is required because the file opening may have been
   /// triggerd by the system (via a drag and drop on the icon from the Finder)
   /// and thus the event loop may not have initiated.
   class FileOpenEvent : public QEvent {
       public:
          FileOpenEvent(QString const& file) : QEvent(QEvent::User), m_file(file) { }
          QString file() { return m_file; }
       private:
          QString m_file;
   };

} // end namespace QCDBEdit

#endif
