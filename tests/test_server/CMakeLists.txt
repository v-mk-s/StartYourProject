cmake_minimum_required(VERSION 3.14)
project(test_server_syp)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-Wall -Wextra -Werror -ggdb3 -fprofile-arcs -ftest-coverage -O0")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -coverage -lgcov" )

file(GLOB SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

find_package(GTest REQUIRED)
find_package(Threads REQUIRED)

add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC ${SERVER_SYP_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} ${SERVER_SYP_LIBRARIES} GTest::GTest gtest_main Threads::Threads -lgmock -lgtest)
