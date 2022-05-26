cmake_minimum_required(VERSION 3.14)
project(StartYourProject)

set(CMAKE_C_FLAGS ${CMAKE_C_FLAGS} "-Wall -Wpedantic -Wextra")

add_subdirectory(server)
add_subdirectory(client)

add_subdirectory(tests)

message("SERVER_SYP_INCLUDE_DIRS = ${SERVER_SYP_INCLUDE_DIRS}")
message("SERVER_SYP_LIBRARIES = ${SERVER_SYP_LIBRARIES}")

message("CLIENT_SYP_CORE_INCLUDE_DIRS = ${CLIENT_SYP_CORE_INCLUDE_DIRS}")
message("CLIENT_SYP_CORE_LIBRARIES = ${CLIENT_SYP_CORE_LIBRARIES}")

# message("CLIENT_SYP_QT_INCLUDE_DIRS = ${CLIENT_SYP_QT_INCLUDE_DIRS}")
# message("CLIENT_SYP_QT_LIBRARIES = ${CLIENT_SYP_QT_LIBRARIES}")
