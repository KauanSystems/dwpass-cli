cmake_minimum_required(VERSION 3.20)

project(dwpass)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

FetchContent_Declare(
    core_repo
    GIT_REPOSITORY https://github.com/KauanSystems/dwpass-core.git
    GIT_TAG        main
)

FetchContent_MakeAvailable(core_repo)

include_directories(${CMAKE_CURRENT_BINARY_DIR}/_deps/core_repo-src/core/include/command)
include_directories(${CMAKE_CURRENT_BINARY_DIR}/_deps/core_repo-src/core/include/logic)

include_directories(${CMAKE_SOURCE_DIR}/program/include/)
include_directories(${CMAKE_SOURCE_DIR}/program/include/cli/)

add_subdirectory(${CMAKE_CURRENT_BINARY_DIR}/_deps/core_repo-src/core/)
add_subdirectory(program)

file(COPY
    ${CMAKE_CURRENT_BINARY_DIR}/_deps/core_repo-src/assets

    DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/program/src/cli/
)
