cmake_minimum_required(VERSION 3.14)
project(boost_testing)

set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-Wall -Wextra")

add_executable(${PROJECT_NAME} server.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC ${SERVER_SYP_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} ${SERVER_SYP_LIBRARIES} -lpthread)
