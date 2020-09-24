# --------------------- #
# (C) 2020 madoodia.com #
# --------------------- #

cmake_minimum_required(VERSION 3.14)

project(CPPListModelsInQML LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(src)

# find_package(QT NAMES Qt6 Qt5 COMPONENTS Core Gui Quick Qml REQUIRED)
# find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core Gui Quick Qml REQUIRED)
find_package(Qt5 COMPONENTS Core Widgets Gui Quick Qml REQUIRED)

set(SOURCES
  main.cpp
  src/checklistmodel.cpp
)

set(RESOURCES
  qml.qrc
)

add_executable(CPPListModelsInQML ${SOURCES} ${RESOURCES})

target_compile_definitions(CPPListModelsInQML
  PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)
target_link_libraries(CPPListModelsInQML
  PRIVATE Qt${QT_VERSION_MAJOR}::Core
          Qt${QT_VERSION_MAJOR}::Gui
          Qt${QT_VERSION_MAJOR}::Quick
          Qt${QT_VERSION_MAJOR}::Qml
)
