cmake_minimum_required(VERSION 3.14)
project(client_syp)

set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-Wall -Wextra")

file(GLOB SOURCES basic/*.cpp clientui/*.cpp network/*.cpp client_uc/*.cpp)
file(GLOB INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR} basic clientui network client_uc ${CMAKE_HOME_DIRECTORY}/general_utils)

add_library(${PROJECT_NAME} STATIC ${SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC ${INCLUDE_DIRS} SYP_GENERAL_INCLUDE_DIRS)

set(CLIENT_SYP_LIBRARIES ${PROJECT_NAME} PARENT_SCOPE)
set(CLIENT_SYP_INCLUDE_DIRS ${INCLUDE_DIRS} PARENT_SCOPE)
