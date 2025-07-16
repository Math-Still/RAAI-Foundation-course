cmake_minimum_required(VERSION 3.16)
project(RAAI-Foundation-course VERSION 1.0.0 LANGUAGES CXX)

# 设置C++标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 设置编译选项
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -O2")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g -O0")

# 设置输出目录
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# 启用测试
enable_testing()

# 添加子目录
add_subdirectory(1-ProgrammingLanguage)
add_subdirectory(2-Linux)
add_subdirectory(3-Algorithm&Datastructure)
add_subdirectory(LinearAlgebra)
add_subdirectory(Robotics)

# 配置版本信息
configure_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/version.h.in"
    "${CMAKE_CURRENT_BINARY_DIR}/version.h"
)

# 安装规则
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/docs/
        DESTINATION share/doc/raai-foundation-course
        FILES_MATCHING PATTERN "*.md")

# 创建包配置
include(CMakePackageConfigHelpers)
write_basic_package_version_file(
    "${CMAKE_CURRENT_BINARY_DIR}/RAAI-Foundation-courseConfigVersion.cmake"
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY AnyNewerVersion
) 