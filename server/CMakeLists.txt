cmake_minimum_required(VERSION 3.14)
project(server_syp)

set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-Wall -Wextra -Werror")

file(GLOB SOURCES handlers/*.cpp router/*.cpp server_uc/*.cpp)
file(GLOB INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR} handlers router server_uc)

add_library(${PROJECT_NAME} STATIC ${SOURCES})

set(SERVER_SYP_LIBRARIES ${PROJECT_NAME} PARENT_SCOPE)
set(SERVER_SYP_INCLUDE_DIRS ${INCLUDE_DIRS} PARENT_SCOPE)