cmake_minimum_required(VERSION 3.10)

project(QMEM)

find_package(wxWidgets REQUIRED core base)

include(${wxWidgets_USE_FILE})

set(SRCS main.cpp MyFrame.cpp)

add_executable(QMEM ${SRCS})

target_link_libraries(QMEM ${wxWidgets_LIBRARIES})

