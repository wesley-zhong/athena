cmake_minimum_required(VERSION 3.0.0)
project(common VERSION 0.1.0 LANGUAGES C CXX)
# 如果代码需要支持C++11，就直接加上这句
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
# 如果想要生成的可执行文件拥有符号表，可以gdb调试，就直接加上这句
add_definitions("-Wall -g")
# 打印消息
message("begin to compiler cmmon ")

# 设置变量，下面的代码都可以用到
set(LIBUV ${PROJECT_SOURCE_DIR}/../3rd/libuv)
set(SOL2 ${PROJECT_SOURCE_DIR}/../3rd/sol2)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/../libs)


message("============= libue== ${LIBUV}")
include_directories(${LIBUV}/include  ${SOL2}/include ${COMMON})

# 获取路径下所有的.cpp/.c/.cc文件，并赋值给变量中
aux_source_directory(${PROJECT_SOURCE_DIR}  CPP_FILES)
add_library(${PROJECT_NAME} STATIC ${CPP_FILES})

link_directories(${PROJECT_SOURCE_DIR}/../libs)
set (PROJECT_LINK_LIBS uv)

# 链接操作
target_link_libraries(${PROJECT_NAME} ${PROJECT_LINK_LIBS} )





