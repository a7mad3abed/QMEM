cmake_minimum_required(VERSION 3.10)

project(QMEM)

find_package(wxWidgets REQUIRED COMPONENTS core base richtext html xml)

include(${wxWidgets_USE_FILE})

if(UNIX)
    include_directories(/usr/include)
    link_directories(/usr/lib)
endif(UNIX)

set(SRCS main.cpp MainFrame.cpp LearnWindow.h LearnWindow.cpp TextEntryWindow.cpp TextEntryWindow.h Results_Dlg.cpp DB_Manager.cpp EditText.cpp EditText.h sqlite3.c)

add_executable(QMEM WIN32 ${SRCS})

target_link_libraries(QMEM ${wxWidgets_LIBRARIES} )

add_custom_command(TARGET QMEM PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/images $<TARGET_FILE_DIR:QMEM>/images)
