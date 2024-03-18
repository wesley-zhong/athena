cmake_minimum_required(VERSION 3.5.0)
project(engine-lua VERSION 0.1.0 LANGUAGES C CXX)

# 如果代码需要支持C++11，就直接加上这句
# SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
# 如果想要生成的可执行文件拥有符号表，可以gdb调试，就直接加上这句
set(CMAKE_CXX_STANDARD 17)
add_definitions("-Wall -g")

#set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/../libs)

# 设置变量
set (SOLUTION_DIR  ${PROJECT_SOURCE_DIR}/..)
set(ENGINE_DIR  ${SOLUTION_DIR}/engine)
message("======== GGGGGGGGGGG: ${SOLUTION_DIR}")


set(LIBUV ${SOLUTION_DIR}/3rd/libuv)
set(3RD ${SOLUTION_DIR}/3rd)
set(SOL2 ${SOLUTION_DIR}/3rd/sol2)
set(LUA ${SOLUTION_DIR}/3rd/lua)

set(ENGINE_COMMON ${ENGINE_DIR}/common)
set(ENGINE_DB ${ENGINE_DIR}/db)
set(ENGINE_NETWORK ${ENGINE_DIR}/network)
set(ENGINE_SERVERIAL ${ENGINE_DIR}/serialization)
set(ENGINE_UTILS ${ENGINE_DIR}/utils)
set(SPDLOG ${PROJECT_SOURCE_DIR}/../3rd/spdlog)

include_directories(${LIBUV}/include
    ${SOL2}/include
    ${LUA}
    ${3RD}
    ${SPDLOG}/include
    ${3RD}/mysql
    ${3RD}/hiredis
    ${ENGINE_COMMON}
    ${ENGINE_DB}
    ${ENGINE_NETWORK}
    ${ENGINE_SERVERIAL}
    ${ENGINE_UTILS}
    ${PROJECT_SOURCE_DIR}/lib
    )

# 获取路径下所有的.cpp/.c/.cc文件，并赋值给变量中
aux_source_directory(${PROJECT_SOURCE_DIR}/  CPP_FILES)
add_subdirectory(${PROJECT_SOURCE_DIR}/lib)

# linked libs
link_directories(${SOLUTION_DIR}/libs)
set(PROJECT_LINK_LIBS uv lua mysqlclient pdlog hiredis engine)
# 生成可执行文件
add_executable(${PROJECT_NAME}  ${CPP_FILES})

message("======== begin to configure game libsDir: ${SOLUTION_DIR}/libs") 
message("======== begin to configure game libs: ${PROJECT_LINK_LIBS}")
message("======== begin to configure game cpps:  ${CPP_FILES}")

# 链接操作
target_link_libraries(${PROJECT_NAME} ${PROJECT_LINK_LIBS})
set_target_properties(${PROJECT_NAME} PROPERTIES CXX_STANDARD 17)
