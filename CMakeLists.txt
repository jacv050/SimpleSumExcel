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

#Find Boost
set(Boost_USE_STATIC_LIBS ON)
find_package(Boost 1.5 REQUIRED COMPONENTS filesystem date_time)
include_directories(${Boost_INCLUDE_DIRS})
link_directories(${Boost_LIBRARY_DIRS} )

#ExcelFormat library
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/ExcelFormat")
SET(EXCELFORMAT_ROOT "${CMAKE_CURRENT_LIST_DIR}/ExcelFormat")
find_package(ExcelFormat REQUIRED)
#include_directories(${EXCELFORMAT_INCLUDE_DIRS}) #${EXCELFORMAT_LIBRARIES}

#Xlnt Library
list(APPEND CMAKE_PREFIX_PATH "${CMAKE_CURRENT_SOURCE_DIR}/Xlnt/lib/cmake/xlnt")
find_package(Xlnt REQUIRED)
include_directories(${XLNT_INCLUDE_DIR} ${EXCELFORMAT_INCLUDE_DIRS})
get_target_property(XLNT_LIBRARIES xlnt::xlnt IMPORTED_IMPLIB_DEBUG)

add_executable( main WIN32 ${GUISOURCES} ${GUIHEADERS} ${GUIPAGESHEADERS} ${GUIPAGESSOURCES} ${SRCHEADERS} ${SRCSOURCES})
target_link_libraries( main Qt5::Widgets Qt5::Core Qt5::WinMain ${EXCELFORMAT_LIBRARIES} Boost::filesystem Boost::date_time xlnt::xlnt ${EXCELFORMAT_LIBRARIES})