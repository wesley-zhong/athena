cmake_minimum_required(VERSION 3.5.0)
project(engine VERSION 0.1.0 LANGUAGES C CXX)

# 支持C++11，
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS} -std=c++0x")
add_definitions("-Wall -g")


# 设置变量
set (SOLUTION_DIR  ${PROJECT_SOURCE_DIR}/..)
set(LIBUV ${SOLUTION_DIR}/3rd/libuv)
set(3RD ${SOLUTION_DIR}/3rd)
set(SOL2 ${SOLUTION_DIR}/3rd/sol2)
set(LUA ${SOLUTION_DIR}/3rd/lua)
set(SPDLOG ${SOLUTION_DIR}/3rd/spdlog)
set(ENGINE_DIR  ${SOLUTION_DIR}/engine)


set(ENGINE_COMMON ${ENGINE_DIR}/common)
set(ENGINE_DB ${ENGINE_DIR}/db)
set(ENGINE_NETWORK ${ENGINE_DIR}/network)
set(ENGINE_SERVERIAL ${ENGINE_DIR}/serialization)
set(ENGINE_UTILS ${ENGINE_DIR}/utils)
message("PPPPPPPPPPPPP: ${SOLUTION_DIR}/libs")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${SOLUTION_DIR}/libs)


include_directories(${LIBUV}/include
    ${SOL2}/include
    ${LUA}
    ${3RD}
    ${3RD}/mysql
    ${3RD}/hiredis
    ${SPDLOG}/include
    ${ENGINE_COMMON}
    ${ENGINE_DB}
    ${ENGINE_NETWORK}
    ${ENGINE_SERVERIAL}
    ${ENGINE_UTILS}
    )
# 获取路径下所有的.cpp/.c/.cc文件，并赋值给变量中
aux_source_directory(${ENGINE_COMMON}/  COMMON_CPP_FILES)
aux_source_directory(${ENGINE_DB}/  DB_CPP_FILES)
aux_source_directory(${ENGINE_NETWORK}/  NET_WORK_CPP_FILES)
aux_source_directory(${ENGINE_SRCRIPT}/  SCRIPT_CPP_FILES)
aux_source_directory(${ENGINE_SERVERIAL}/  SERIAL_CPP_FILES)
aux_source_directory(${ENGINE_UTILS}/  UTILS_CPP_FILES)

# 生成libs
add_library(${PROJECT_NAME} STATIC
    ${COMMON_CPP_FILES}
    ${DB_CPP_FILES}
    ${NET_WORK_CPP_FILES}
    ${SCRIPT_CPP_FILES}
    ${SERIAL_CPP_FILES}
    ${UTILS_CPP_FILES}
)

# linked libs
link_directories(${PROJECT_SOURCE_DIR}/../libs)
set(PROJECT_LINK_LIBS uv lua spdlog)

# 链接操作
target_link_libraries(${PROJECT_NAME} ${PROJECT_LINK_LIBS})

set_target_properties(${PROJECT_NAME} PROPERTIES CXX_STANDARD 17)
