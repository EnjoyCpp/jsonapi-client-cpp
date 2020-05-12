cmake_minimum_required(VERSION 2.4)

project(jsonapi-client-cpp)
set(CMAKE_BUILD_TYPE Release)

include_directories("${PROJECT_SOURCE_DIR}/src")
FILE(GLOB SOURCES ${PROJECT_SOURCE_DIR}/src/*.cpp)
FILE(GLOB HEADERS ${PROJECT_SOURCE_DIR}/src/*.h)

# Shared library
add_library(jsonapiclient SHARED ${SOURCES})

# Dynamically linked libraries
target_link_libraries(jsonapiclient curl)
target_link_libraries(jsonapiclient jsoncpp)

# SOVERSION
set_property(TARGET jsonapiclient PROPERTY SOVERSION 0)

# Installing
include(GNUInstallDirs)
install(TARGETS jsonapiclient LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
install(FILES ${HEADERS} DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
