######################################################################
#
#  This is the QCDBEdit project file. 
#
######################################################################

TEMPLATE     =  app
DEPENDPATH  +=  .
CONFIG      +=  no_keywords qt opengl qchem_ui
RESOURCES   +=  QCDBEdit.qrc
ICON         =  resources/QCDBEdit.icns
QT          +=  sql xml
OBJECTS_DIR  =  build
DESTDIR      =  .


#################################
# System specific configuration #
#################################

macx {
   INCLUDEPATH += /usr/local/include
   INCLUDEPATH += /Library/Frameworks/QtSql.framework/Headers
   CONFIG += debug
}

win32 {
   RC_FILE += windows.rc
}

linux {
}



###############
# Input Files #
###############

HEADERS += \
   QCDBEditApplication.h  QMsgBox.h  MainWindow.h  OptionDatabase.h  Option.h \
   EditOptionDialog.h  OptionListEditor.h  OptionNumberEditor.h

SOURCES += main.C \
   QCDBEditApplication.C  QMsgBox.C  MainWindow.C  OptionDatabase.C  Option.C \
   EditOptionDialog.C  OptionListEditor.C  OptionNumberEditor.C

FORMS += \
   MainWindow.ui  EditOptionDialog.ui  OptionListEditor.ui  OptionNumberEditor.ui
