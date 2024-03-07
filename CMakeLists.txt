cmake_minimum_required(VERSION 3.0.0)
project(athena VERSION 0.1.0 LANGUAGES C CXX)
# 如果代码需要支持C++11，就直接加上这句
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
# 如果想要生成的可执行文件拥有符号表，可以gdb调试，就直接加上这句
add_definitions("-Wall -g")

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
# 打印消息
message("begin to compiler game ")

# 设置变量，下面的代码都可以用到

set(COMMON ${PROJECT_SOURCE_DIR}/common)
set(GAME ${PROJECT_SOURCE_DIR}/game)

add_subdirectory(${COMMON})
add_subdirectory(${GAME})