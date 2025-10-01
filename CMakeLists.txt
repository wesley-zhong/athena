cmake_minimum_required(VERSION 3.5.0)


project(athena VERSION 0.1.0 LANGUAGES C CXX)
# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
# 如果代码需要支持C++11，就直接加上这句
if(UNIX)
	SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++17")
endif()
# 如果想要生成的可执行文件拥有符号表，可以gdb调试，就直接加上这句

add_compile_definitions(WIN32_LEAN_AND_MEAN NOMINMAX)
add_definitions("-Wall -g")
add_compile_options(-Wno-unused-function)


#set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
# 打印消息
message("begin to compiler game ")

# 设置变量，下面的代码都可以用到
set(ENGINE ${PROJECT_SOURCE_DIR}/engine)
set(ENGINE-LUA ${PROJECT_SOURCE_DIR}/engine-lua)
set(GAME ${PROJECT_SOURCE_DIR}/game)


add_subdirectory(${ENGINE})
add_subdirectory(${ENGINE-LUA})
add_subdirectory(${GAME})