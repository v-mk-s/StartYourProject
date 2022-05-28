cmake_minimum_required(VERSION 3.14)
project(server_syp_network)

find_package(Boost COMPONENTS REQUIRED json)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-Wall -Wpedantic -Wextra")

file(GLOB SOURCES
        main.cpp
        listener/listener.cpp
        router/router.cpp
        request_response/request_response.impl
        server_impl/server.cpp
        temp/database.cpp
)

file(GLOB INCLUDE_DIRS
        ${CMAKE_CURRENT_SOURCE_DIR}
        router
        listener
        request_response
        server_impl
        temp
)

add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC 
        ${INCLUDE_DIRS} 
        ${SERVER_SYP_DATABASE_INCLUDE_DIRS}
        ${SERVER_SYP_CORE_INCLUDE_DIRS} 
)

target_link_libraries(${PROJECT_NAME} 
        ${SERVER_SYP_CORE_LIBRARIES}
        ${SERVER_SYP_DATABASE_LIBRARIES}
        Boost::json -lpthread
)

set(SERVER_SYP_NETWORK_LIBRARIES ${PROJECT_NAME} PARENT_SCOPE)
set(SERVER_SYP_NETWORK_INCLUDE_DIRS ${INCLUDE_DIRS} PARENT_SCOPE)