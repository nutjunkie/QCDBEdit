set(LIB QCDB)

find_package(Qt5 COMPONENTS Core Gui Widgets Sql REQUIRED)

set( HEADERS
   EditOptionDialog.h
   MainWindow.h
   Option.h
   OptionDatabase.h
   OptionListEditor.h
   OptionNumberEditor.h
   QCDBEditApplication.h
   QMsgBox.h
)

set( SOURCES
   EditOptionDialog.C
   MainWindow.C
   Option.C
   OptionDatabase.C
   OptionListEditor.C
   OptionNumberEditor.C
   QCDBEditApplication.C
   QMsgBox.C
)

set( UI_FILES
   EditOptionDialog.ui
   MainWindow.ui
   OptionListEditor.ui
   OptionNumberEditor.ui
)

qt5_wrap_ui(UI_HEADERS ${UI_FILES} )
qt5_wrap_cpp(SOURCES ${HEADERS} )

add_library(${LIB} ${SOURCES} ${UI_HEADERS})

target_link_libraries(${LIB} PRIVATE
   Qt5::Core
   Qt5::Gui
   Qt5::Sql
   Qt5::Widgets
)
