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

#include "QCDBEditApplication.h"
#include "QMsgBox.h"
#include "MainWindow.h"
#include <QFileOpenEvent>
#include <QString>
#include <QDir>

#include <QtDebug>


namespace QCDBEdit {

QCDBEditApplication::QCDBEditApplication(int &argc, char **argv )
  : QApplication(argc, argv)
{
   setOrganizationDomain("iqmol.org");
   setApplicationName("QCDBEdit");
   QDir dir(QApplication::applicationDirPath());

#ifdef Q_WS_MAC
   dir.cdUp();  dir.cd("Frameworks");
   QApplication::setLibraryPaths(QStringList(dir.absolutePath()));
   dir.cdUp();  dir.cd("PlugIns");
   QApplication::addLibraryPath(dir.absolutePath());
#else
   QApplication::addLibraryPath(dir.absolutePath() + "/plugins");
#endif
   m_mainWindow = new MainWindow();
   m_mainWindow->show();
}


QCDBEditApplication::~QCDBEditApplication()
{
   if (m_mainWindow) delete m_mainWindow;
}


void QCDBEditApplication::queueOpenFiles(QStringList const& files)
{
   QStringList::const_iterator iter;
   for (iter = files.begin(); iter != files.end(); ++iter) {
       FileOpenEvent* event = new FileOpenEvent(*iter);
       QApplication::postEvent(this, event, Qt::LowEventPriority);
   }
}


void QCDBEditApplication::open(QString const& file)
{
   m_mainWindow->open(file);
}


bool QCDBEditApplication::event(QEvent* event)
{
   bool accepted(false);

   switch (event->type()) {
      case QEvent::FileOpen: {
         QString file(static_cast<QFileOpenEvent*>(event)->file());
         queueOpenFiles(QStringList(file));
         accepted = true;
         } break;

      case QEvent::Close: {
         QCloseEvent *closeEvent = static_cast<QCloseEvent *>(event);
         qDebug() << "request to close" << closeEvent;
         m_mainWindow->quit();
         accepted = QApplication::event(event);
         } break;

      case QEvent::User: {
         QString file(static_cast<FileOpenEvent*>(event)->file());
         open(file);
         accepted = true;
         } break;

      default:
         accepted = QApplication::event(event);
         break;
   }

   return accepted;
}


} // end namespace IQmol
