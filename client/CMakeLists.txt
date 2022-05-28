add_subdirectory(core)
# add_subdirectory(qt)

set(CLIENT_SYP_CORE_LIBRARIES ${CLIENT_SYP_CORE_LIBRARIES} PARENT_SCOPE)
set(CLIENT_SYP_CORE_INCLUDE_DIRS ${CLIENT_SYP_CORE_INCLUDE_DIRS} PARENT_SCOPE)

# set(CLIENT_SYP_QT_LIBRARIES ${CLIENT_SYP_QT_LIBRARIES} PARENT_SCOPE)
# set(CLIENT_SYP_QT_INCLUDE_DIRS ${CLIENT_SYP_QT_INCLUDE_DIRS} PARENT_SCOPE)

cmake_minimum_required(VERSION 3.5)

project(SYPcmakeVer_1 VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#set_property(SOURCE login_page.h PROPERTY SKIP_AUTOUIC ON)
#set_property(SOURCE login_page.cpp PROPERTY SKIP_AUTOUIC ON)
#set_property(SOURCE login_page.ui PROPERTY SKIP_AUTOUIC ON)


find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)
include_directories(
    ../general_utils
    core/client_uc
    core/clientui
    core/basic

    client
    client/include
#    client/include/pages
    client/include/process

    client/src
#    client/src/pages
    client/src/process
)
include_directories(core include ${PROJECT_SOURCE_DIR}/build)

set(PROJECT_SOURCES
        client/src/register_page.cpp
        client/include/register_page.h
        client/src/register_page.ui

        client/main.cpp
        client/src/login_page.cpp
        client/include/login_page.h
        client/src/login_page.ui

        client/src/publish_post_page.cpp
        client/include/publish_post_page.h
        client/src/publish_post_page.ui

        client/src/project_page.cpp
        client/include/project_page.h
        client/src/project_page.ui

        client/src/process/general.cpp
        client/include/process/general.h

        ../general_utils/utils.hpp
        core/client_uc/usecases.hpp
        core/client_uc/usecases.cpp
        core/clientui/clientui.hpp
        core/basic/validation.cpp
        core/basic/validation.hpp

#        for better architecture...
#        client/main.cpp
#        client/src/pages/login_page.cpp
#        client/include/pages/login_page.h
#        client/src/pages/login_page.ui

#        client/src/pages/publish_post_page.cpp
#        client/include/pages/publish_post_page.h
#        client/src/pages/publish_post_page.ui

#        client/src/process/general.cpp
#        client/include/process/general.h

)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(SYPcmakeVer_1
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET SYPcmakeVer_1 APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(SYPcmakeVer_1 SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(SYPcmakeVer_1
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_include_directories(SYPcmakeVer_1 PUBLIC ${CLIENT_SYP_CORE_INCLUDE_DIRS})
target_link_libraries(SYPcmakeVer_1 PRIVATE ${CLIENT_SYP_CORE_LIBRARIES} Qt${QT_VERSION_MAJOR}::Widgets)

set_target_properties(SYPcmakeVer_1 PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(SYPcmakeVer_1)
endif()
