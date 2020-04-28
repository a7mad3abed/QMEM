cmake_minimum_required(VERSION 3.10)

project(QMEM)

find_package(wxWidgets REQUIRED COMPONENTS core base richtext html xml)

include(${wxWidgets_USE_FILE})

if(UNIX)
    include_directories(/usr/include)
    link_directories(/usr/lib)
endif(UNIX)

set(SRCS main.cpp MainWindow.cpp LearnWindow.h LearnWindow.cpp textEntryDialog.h textEntryDialog.cpp Results_Dlg.cpp DB_Manager.cpp sqlite3.c)

add_executable(QMEM WIN32 ${SRCS})

target_link_libraries(QMEM ${wxWidgets_LIBRARIES})
