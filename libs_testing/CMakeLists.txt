cmake_minimum_required(VERSION 3.14)
project(boost_testing)

find_package(Boost COMPONENTS REQUIRED json)

set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-Wall -Wextra")

add_executable(server server.cpp)
add_executable(client client.cpp)

target_include_directories(server PUBLIC ${SERVER_SYP_INCLUDE_DIRS})
target_link_libraries(server ${SERVER_SYP_LIBRARIES} Boost::json -lpthread)

target_include_directories(client PUBLIC ${SERVER_SYP_INCLUDE_DIRS})
target_link_libraries(client ${SERVER_SYP_LIBRARIES} Boost::json -lpthread)
