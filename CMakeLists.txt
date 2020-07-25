CMAKE_MINIMUM_REQUIRED (VERSION 2.8.6)
project(motesque-eigen)

set( CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_SOURCE_DIR})
if(UNIX)
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=gnu++11")
endif()

find_package(EIGEN REQUIRED)
if(NOT ${EIGEN_VERSION} STREQUAL "3.3.5")
    message(SEND_ERROR "Eigen Library ${EIGEN_VERSION} is not supported")
endif()

include_directories(${CMAKE_SOURCE_DIR} ${EIGEN_INCLUDE_DIRS})

add_executable(motesque-eigen main.cpp)

install(TARGETS motesque-eigen
        RUNTIME DESTINATION /usr/local/bin/)