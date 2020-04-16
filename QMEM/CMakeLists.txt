cmake_minimum_required(VERSION 3.10)

project(QMEM)

find_package(wxWidgets REQUIRED COMPONENTS core base)

include(${wxWidgets_USE_FILE})

set(SRCS main.cpp MainWindow.cpp LearnWindow.h LearnWindow.cpp textEntryDialog.h textEntryDialog.cpp)

add_executable(QMEM WIN32 ${SRCS})

target_link_libraries(QMEM ${wxWidgets_LIBRARIES})
