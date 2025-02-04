cmake_minimum_required(VERSION 3.5.0)
project(game VERSION 0.1.0 LANGUAGES C CXX)
#SET(CMAKE_CXX_FLAGS "-g -Wall -Werror -std=c++11")
#SET(CMAKE_CXX_FLAGS "-g -Wall -std=c++11")
set(CMAKE_CXX_STANDARD 17)
# 如果想要生成的可执行文件拥有符号表，可以gdb调试，就直接加上这句

add_definitions("-Wall -g")


# 设置变量
set (SOLUTION_DIR  ${PROJECT_SOURCE_DIR}/..)
set(ENGINE_DIR  ${SOLUTION_DIR}/engine)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${SOLUTION_DIR}/libs)

set(LIBUV ${SOLUTION_DIR}/3rd/libuv)
set(3RD ${SOLUTION_DIR}/3rd)
set(SOL2 ${SOLUTION_DIR}/3rd/sol2)
set(LUA ${SOLUTION_DIR}/3rd/lua)
set(SPDLOG ${SOLUTION_DIR}/3rd/spdlog)
#set(PROTO_BUF ${SOLUTION_DIR}/3rd/protobuf)

set(ENGINE_COMMON ${ENGINE_DIR}/common)
set(ENGINE_DB ${ENGINE_DIR}/db)
set(ENGINE_NETWORK ${ENGINE_DIR}/network)
set(ENGINE_SERVERIAL ${ENGINE_DIR}/serialization)
set(ENGINE_UTILS ${ENGINE_DIR}/utils)
set(PROTO_GEN ${PROJECT_SOURCE_DIR}/progen)


include_directories(${LIBUV}/include
    ${SOL2}/include
    ${LUA}
    ${3RD}
    ${3RD}/mysql
    ${3RD}/hiredis
    ${SPDLOG}/include
    ${ENGINE_DIR}
    ${ENGINE_COMMON}
    ${ENGINE_DB}
    ${ENGINE_NETWORK}
    ${ENGINE_SERVERIAL}
    ${ENGINE_UTILS}
    )
    include_directories(
        ${PROJECT_SOURCE_DIR}/src/network
        ${PROJECT_SOURCE_DIR}/src/objs 
        ${PROTO_GEN}
    )


# 获取路径下所有的.cpp/.c/.cc文件，并赋值给变量中
aux_source_directory(${PROJECT_SOURCE_DIR}/src  CPP_FILES)
aux_source_directory(${PROJECT_SOURCE_DIR}/src/network  CPP_SERVICES)
aux_source_directory(${PROJECT_SOURCE_DIR}/src/objs  OBJS)
aux_source_directory(${PROTO_GEN}  PROTO_OBJS)

link_directories(${PROJECT_SOURCE_DIR}/../libs)

set (PROJECT_LINK_LIBS  uv lua mysqlclient  hiredis  enginelua)
message("======== begin to configure game libsDir: ${PROTO_OBJS}") 


# 生成可执行文件
add_executable(${PROJECT_NAME}  ${CPP_FILES} ${OBJS} ${PROTO_OBJS} ${CPP_SERVICES})
find_package(protobuf CONFIG REQUIRED)
#find_package(PkgConfig REQUIRED)
# these calls create special `PkgConfig::<MODULE>` variables
#pkg_check_modules(protobuf REQUIRED IMPORTED_TARGET protobuf)
#pkg_check_modules(protobuf-lite REQUIRED IMPORTED_TARGET protobuf-lite)

# 链接操作
target_link_libraries(${PROJECT_NAME}  ${PROJECT_LINK_LIBS} pthread protobuf::libprotobuf)
set_target_properties(${PROJECT_NAME} PROPERTIES CXX_STANDARD 17)

