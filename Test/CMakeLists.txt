cmake_minimum_required(VERSION 3.10)
project(Test)

include_directories(${CMAKE_CURRENT_LIST_DIR}/../ImgLib/include)
include_directories(${CMAKE_CURRENT_LIST_DIR}/../ImgLib/3rdParty/libyuv/include)

file(GLOB TEST_FILES "${CMAKE_CURRENT_LIST_DIR}/*.cpp")

add_executable(Test ${TEST_FILES})

target_link_libraries(Test ImgLib)
