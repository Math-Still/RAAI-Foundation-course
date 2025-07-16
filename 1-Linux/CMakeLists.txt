# Linux 系统编程模块
set(MODULE_NAME "Linux")

# 系统调用示例
add_executable(linux_syscalls
    syscalls/main.cpp
    syscalls/file_ops.cpp
)

target_include_directories(linux_syscalls PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

# 进程管理示例
add_executable(process_management
    process/main.cpp
    process/fork_example.cpp
)

target_include_directories(process_management PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

# 网络编程示例
add_executable(network_programming
    network/socket_example.cpp
    network/server.cpp
    network/client.cpp
)

target_include_directories(network_programming PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

# 添加测试
add_test(NAME linux_syscalls_test COMMAND linux_syscalls)
add_test(NAME process_management_test COMMAND process_management)
add_test(NAME network_programming_test COMMAND network_programming)

# 安装规则
install(TARGETS linux_syscalls process_management network_programming
        RUNTIME DESTINATION bin/${MODULE_NAME}
        LIBRARY DESTINATION lib/${MODULE_NAME}
        ARCHIVE DESTINATION lib/${MODULE_NAME}
) 