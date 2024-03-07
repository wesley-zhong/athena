cmake_minimum_required(VERSION 3.0.0)
project(game VERSION 0.1.0 LANGUAGES C CXX)
# 如果代码需要支持C++11，就直接加上这句
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
# 如果想要生成的可执行文件拥有符号表，可以gdb调试，就直接加上这句
add_definitions("-Wall -g")



# 设置变量，下面的代码都可以用到
set(LIBUV ${PROJECT_SOURCE_DIR}/../3rd/libuv)
set(SOL2 ${PROJECT_SOURCE_DIR}/../sol2)
set(COMMON ${PROJECT_SOURCE_DIR}/../common)
#set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

include_directories(${LIBUV}/include  ${SOL2}/include  ${COMMON})
message("======== begin to compiler game  ${COMMON}")

# 获取路径下所有的.cpp/.c/.cc文件，并赋值给变量中
aux_source_directory(${PROJECT_SOURCE_DIR}/src  CPP_FILES)
link_directories(${PROJECT_SOURCE_DIR}/../libs)
set (PROJECT_LINK_LIBS uv  common)

# 生成可执行文件
add_executable(${PROJECT_NAME}   ${CPP_FILES})

# 链接操作
target_link_libraries(${PROJECT_NAME}  ${PROJECT_LINK_LIBS} )
