cmake_minimum_required(VERSION 3.14.4)

if (UNIX AND NOT APPLE)
    set(LINUX TRUE)
endif()

set(targetName QCDBEdit)
project(${targetName} VERSION 3.1.1 LANGUAGES CXX C)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE Release)
set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wno-deprecated")
set(CMAKE_MODULE_PATH ${QCDBEdit_SOURCE_DIR}/cmake)


find_package(Qt5 COMPONENTS Core Gui Xml Widgets REQUIRED)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)

include_directories(${CMAKE_CURRENT_BINARY_DIR}/src)

add_subdirectory(src)

if (${Qt5Core_VERSION_STRING} VERSION_GREATER_EQUAL 5.15 )
   qt_add_resources(QCDBEdit_RESOURCES_RCC resources/QCDBEdit.qrc)
else ()
   qt5_add_resources(QCDBEdit_RESOURCES_RCC resources/QCDBEdit.qrc)
endif ()

set(ICON_PATH resources/QCDBEdit.icns)

if (APPLE)
   add_executable(${targetName} 
      MACOSX_BUNDLE
      ${ICON_PATH}
      src/main.C
      ${QCDBEdit_RESOURCES_RCC}
   )
   set_source_files_properties(${ICON_PATH} PROPERTIES MACOSX_PACKAGE_LOCATION Resources)
   file(COPY ${ICON_PATH} DESTINATION "bin/${targetName}.app/Contents/Resources")
endif(APPLE)

if (LINUX)
   add_executable(${targetName} 
      src/main.C
      ${QCDBEdit_RESOURCES_RCC}
   )
endif (LINUX)

if (WIN32)
   set(WIN32_RESOURCES ${CMAKE_CURRENT_SOURCE_DIR}/resources/windows.rc)
   enable_language("RC")

   add_executable(${targetName} 
      src/main.C
      ${QCDBEdit_RESOURCES_RCC}
      ${WIN32_RESOURCES}
   )
   set_target_properties(${targetName} PROPERTIES WIN32_EXECUTABLE ON)
endif (WIN32)


target_link_libraries (${targetName}
   QCDB
   Qt5::Core
   Qt5::Gui
   Qt5::Xml
   Qt5::Widgets
)
