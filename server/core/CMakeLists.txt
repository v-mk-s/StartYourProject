cmake_minimum_required(VERSION 3.14)
project(server_syp_core)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-Wall -Wpedantic -Wextra")

file(GLOB SOURCES 
        server_uc/server_usecases.cpp
        handlers/handlers.impl
)

file(GLOB INCLUDE_DIRS
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_HOME_DIRECTORY}/general_utils
        handlers
        server_uc
        idatabase
        inetwork
)

add_library(${PROJECT_NAME} SHARED ${SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC ${INCLUDE_DIRS})

set(SERVER_SYP_CORE_LIBRARIES ${PROJECT_NAME} PARENT_SCOPE)
set(SERVER_SYP_CORE_INCLUDE_DIRS ${INCLUDE_DIRS} PARENT_SCOPE)