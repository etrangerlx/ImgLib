add_subdirectory(ImgLib)
add_subdirectory(Test)

cmake_minimum_required(VERSION 3.10)
project(ImgTest)

file(GLOB IMAGE_FILE ${CMAKE_CURRENT_LIST_DIR}/image/*.yuv)
message(STATUS "complier path:${CMAKE_BINARY_DIR}")

file(COPY ${IMAGE_FILE} DESTINATION ${CMAKE_BINARY_DIR})
