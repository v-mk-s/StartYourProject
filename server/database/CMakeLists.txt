cmake_minimum_required(VERSION 3.14)
project(server_syp_database)

# find_package(MySQL REQUIRED)

include(FindPkgConfig)
pkg_check_modules(LIBMYSQLCLIENT REQUIRED mysqlclient)

file(GLOB SOURCES
        database.cpp
        dbconnection.cpp
)

file(GLOB INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR} ${SERVER_SYP_CORE_INCLUDE_DIRS})

set(SERVER_SYP_DATABASE_INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR} PARENT_SCOPE)

# include_directories(${MYSQL_INCLUDE_DIR})
# target_link_libraries(cgm ${MYSQL_LIB})