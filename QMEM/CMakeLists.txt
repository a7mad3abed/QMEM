cmake_minimum_required(VERSION 3.10)
project(Qmem VERSION 1.0.0)

find_package(wxWidgets REQUIRED COMPONENTS core base )


include(${wxWidgets_USE_FILE})

set(SRCS main.cpp MyFrame.cpp)

add_executable(Qmem ${SRCS} )


target_link_libraries(Qmem ${wxWidgets_LIBRARIES})