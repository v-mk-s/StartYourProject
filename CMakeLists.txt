cmake_minimum_required(VERSION 3.14)
project(StartYourProject)

set(CMAKE_C_FLAGS ${CMAKE_C_FLAGS} "-Wall -Wpedantic -Wextra -Werror")

add_subdirectory(server)
# add_subdirectory(client)
add_subdirectory(tests)

message("SERVER_SYP_INCLUDE_DIRS = ${SERVER_SYP_INCLUDE_DIRS}")
message("SERVER_SYP_LIBRARIES = ${SERVER_SYP_LIBRARIES}")

add_executable(${PROJECT_NAME} executable/main.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC ${SERVER_SYP_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} PRIVATE ${SERVER_SYP_LIBRARIES})