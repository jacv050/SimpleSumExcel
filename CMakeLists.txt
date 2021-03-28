cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

project(SimpleSumExcel)

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fopenmp -march=native")
#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fopenmp -march=native")

FILE(GLOB GUIHEADERS "gui/*.h*")
FILE(GLOB GUISOURCES "gui/*.cpp")

FILE(GLOB SRCHEADERS "src/*.h*")
FILE(GLOB SRCSOURCES "src/*.cpp")

FILE(GLOB GUIPAGESHEADERS "gui/pages/*.h*")
FILE(GLOB GUIPAGESSOURCES "gui/pages/*.cpp")

#Find QT
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
find_package(Qt5Core)
find_package(Qt5Widgets)

#ExcelFormat library
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/ExcelFormat")
SET(EXCELFORMAT_ROOT "${CMAKE_CURRENT_LIST_DIR}/ExcelFormat")
find_package(ExcelFormat REQUIRED)

add_executable( main WIN32 ${GUISOURCES} ${GUIHEADERS} ${GUIPAGESHEADERS} ${GUIPAGESSOURCES} ${SRCHEADERS} ${SRCSOURCES})
include_directories(${EXCELFORMAT_INCLUDE_DIRS})
target_link_libraries( main Qt5::Widgets Qt5::Core Qt5::WinMain ${EXCELFORMAT_LIBRARIES})