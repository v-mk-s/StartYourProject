cmake_minimum_required(VERSION 3.14)
project(test_client_syp)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-Wall -Wextra -Werror -fprofile-arcs -ftest-coverage -O0")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -coverage -lgcov" )

file(GLOB SOURCES *.cpp)

find_package(GTest REQUIRED)
find_package(Threads REQUIRED)

add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC ${CLIENT_SYP_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} ${CLIENT_SYP_LIBRARIES} GTest::GTest gtest_main Threads::Threads)
