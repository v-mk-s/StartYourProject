cmake_minimum_required(VERSION 3.14)
project(StartYourProject)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_FLAGS ${CMAKE_C_FLAGS} "-Wall -Wpedantic -Wextra")

if(SERVER_EXAMPLE)
    add_subdirectory(server)
    add_subdirectory(libs_testing)
else()
    add_subdirectory(server)
    add_subdirectory(client)
    add_subdirectory(tests)
endif()

message("SERVER_SYP_INCLUDE_DIRS = ${SERVER_SYP_INCLUDE_DIRS}")
message("SERVER_SYP_LIBRARIES = ${SERVER_SYP_LIBRARIES}")

message("CLIENT_SYP_INCLUDE_DIRS = ${CLIENT_SYP_INCLUDE_DIRS}")
message("CLIENT_SYP_LIBRARIES = ${CLIENT_SYP_LIBRARIES}")

# add_executable(${PROJECT_NAME} main.cpp)

# target_include_directories(${PROJECT_NAME} PUBLIC ${CLIENT_SYP_INCLUDE_DIRS})
# target_link_libraries(${PROJECT_NAME} PRIVATE ${CLIENT_SYP_LIBRARIES})
