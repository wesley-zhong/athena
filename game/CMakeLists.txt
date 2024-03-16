cmake_minimum_required(VERSION 3.5.0)
project(game VERSION 0.1.0 LANGUAGES C CXX)
# 如果代码需要支持C++11，就直接加上这句
# SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
# 如果想要生成的可执行文件拥有符号表，可以gdb调试，就直接加上这句
#set(CMAKE_CXX_STANDARD 17)
add_definitions("-Wall -g")


# 设置变量
set (SOLUTION_DIR  ${PROJECT_SOURCE_DIR}/..)
set(ENGINE_DIR  ${SOLUTION_DIR}/engine)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${SOLUTION_DIR}/libs)

set(LIBUV ${SOLUTION_DIR}/3rd/libuv)
set(3RD ${SOLUTION_DIR}/3rd)
set(SOL2 ${SOLUTION_DIR}/3rd/sol2)
set(LUA ${SOLUTION_DIR}/3rd/lua)

set(ENGINE_COMMON ${ENGINE_DIR}/common)
set(ENGINE_DB ${ENGINE_DIR}/db)
set(ENGINE_NETWORK ${ENGINE_DIR}/network)
set(ENGINE_SERVERIAL ${ENGINE_DIR}/serialization)
set(ENGINE_UTILS ${ENGINE_DIR}/utils)

include_directories(${LIBUV}/include
    ${SOL2}/include
    ${LUA}
    ${3RD}
    ${3RD}/mysql
    ${3RD}/hiredis
    ${ENGINE_DIR}
    ${ENGINE_COMMON}
    ${ENGINE_DB}
    ${ENGINE_NETWORK}
    ${ENGINE_SERVERIAL}
    ${ENGINE_UTILS}
    ${PROJECT_SOURCE_DIR}/src/service
    )

# 获取路径下所有的.cpp/.c/.cc文件，并赋值给变量中
aux_source_directory(${PROJECT_SOURCE_DIR}/src  CPP_FILES)
aux_source_directory(${PROJECT_SOURCE_DIR}/src/service  CPP_SERVICES)

link_directories(${PROJECT_SOURCE_DIR}/../libs)
set (PROJECT_LINK_LIBS uv lua engine enginelua)
message("======== begin to configure game libsDir: ${PROJECT_SOURCE_DIR}/../libs") 
message("======== begin to configure game libs: ${PROJECT_LINK_LIBS}")
message("======== begin to configure game cpps:  ${CPP_FILES}")

# 生成可执行文件
add_executable(${PROJECT_NAME}  ${CPP_FILES} ${CPP_SERVICES})

# 链接操作
target_link_libraries(${PROJECT_NAME}  ${PROJECT_LINK_LIBS} )
set_target_properties(${PROJECT_NAME} PROPERTIES CXX_STANDARD 17)

