add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/3rdParty/libyuv)

cmake_minimum_required(VERSION 3.10)
project(ImgLib)
include_directories(${CMAKE_CURRENT_LIST_DIR}/include)
include_directories(${CMAKE_CURRENT_LIST_DIR}/3rdParty/libyuv/include)
file(GLOB IMGLIB_FILES "${CMAKE_CURRENT_LIST_DIR}/src/*.cpp")

add_library(ImgLib STATIC ${IMGLIB_FILES})
target_link_libraries(ImgLib yuv)
