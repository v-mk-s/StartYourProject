cmake_minimum_required(VERSION 3.14)
project(server_syp)

set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-Wall -Wpedantic -Wextra")

file(GLOB SOURCES 
        handlers/handlers.cpp 
        server_uc/server_usecases.cpp 
        database/database.cpp
        server/network/listener/listener.cpp
        network/router/router.cpp
        /network/request_response/request_response.cpp
)

file(GLOB INCLUDE_DIRS
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_HOME_DIRECTORY}/general_utils
        handlers
        router
        server_uc
        database
        network_interface
        network/listener
        network/router
        network/request_response/
)

add_library(${PROJECT_NAME} STATIC ${SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC ${INCLUDE_DIRS})

set(SERVER_SYP_LIBRARIES ${PROJECT_NAME} PARENT_SCOPE)
set(SERVER_SYP_INCLUDE_DIRS ${INCLUDE_DIRS} PARENT_SCOPE)