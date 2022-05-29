cmake_minimum_required(VERSION 3.14)
project(server_syp_database)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-Wall -Wpedantic -Wextra")

file(GLOB SOURCES src/database.cpp)

file(GLOB INCLUDE_DIRS include)

add_library(${PROJECT_NAME} SHARED ${SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC ${INCLUDE_DIRS} ${SERVER_SYP_CORE_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} -lmysqlcppconn8)

set(SERVER_SYP_DATABASE_LIBRARIES ${PROJECT_NAME} PARENT_SCOPE)
set(SERVER_SYP_DATABASE_INCLUDE_DIRS ${INCLUDE_DIRS} PARENT_SCOPE)

