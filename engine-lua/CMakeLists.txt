cmake_minimum_required(VERSION 3.5.0)
project(engine-lua VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}  -std=c++0x")
add_definitions("-Wall -g")

# 设置变量
set (SOLUTION_DIR  ${PROJECT_SOURCE_DIR}/..)
set(ENGINE_DIR  ${SOLUTION_DIR}/engine)


set(LIBUV ${SOLUTION_DIR}/3rd/libuv)
set(3RD ${SOLUTION_DIR}/3rd)
set(SOL2 ${SOLUTION_DIR}/3rd/sol2)
set(LUA ${SOLUTION_DIR}/3rd/lua)

set(ENGINE_COMMON ${ENGINE_DIR}/common)
set(ENGINE_DB ${ENGINE_DIR}/db)
set(ENGINE_NETWORK ${ENGINE_DIR}/network)
set(ENGINE_SERVERIAL ${ENGINE_DIR}/serialization)
set(ENGINE_UTILS ${ENGINE_DIR}/utils)
set(SPDLOG ${SOLUTION_DIR}/3rd/spdlog)

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
set(PROJECT_LINK_LIBS  uv mysqlclient  hiredis  enginelua)
# 生成可执行文件
add_executable(${PROJECT_NAME}  ${CPP_FILES})


# 链接操作
target_link_libraries(${PROJECT_NAME} ${PROJECT_LINK_LIBS})
set_target_properties(${PROJECT_NAME} PROPERTIES CXX_STANDARD 17)
