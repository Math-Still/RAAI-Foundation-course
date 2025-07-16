# 编程语言模块
set(MODULE_NAME "ProgrammingLanguage")

# C++ 基础练习
add_executable(cpp_exercise1_1
    C++/exercises/chapter01/exercise1_1.cpp
)

add_executable(cpp_exercise1_2
    C++/exercises/chapter01/exercise1_2.cpp
)

add_executable(cpp_exercise1_3
    C++/exercises/chapter01/exercise1_3.cpp
)

# C++ 测试
add_executable(cpp_test1_1
    C++/tests/chapter01/test_exercise1_1.cpp
)

# 设置包含目录
target_include_directories(cpp_exercise1_1 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/C++)
target_include_directories(cpp_exercise1_2 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/C++)
target_include_directories(cpp_exercise1_3 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/C++)
target_include_directories(cpp_test1_1 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/C++)

# 添加测试
add_test(NAME cpp_exercise1_1_test COMMAND cpp_exercise1_1)
add_test(NAME cpp_exercise1_2_test COMMAND cpp_exercise1_2)
add_test(NAME cpp_exercise1_3_test COMMAND cpp_exercise1_3)
add_test(NAME cpp_test1_1_test COMMAND cpp_test1_1)

# Python 示例（如果有C++扩展）
if(PYTHON_FOUND)
    add_executable(python_bridge
        C++/python_bridge/main.cpp
    )
    target_link_libraries(python_bridge ${PYTHON_LIBRARIES})
    target_include_directories(python_bridge PRIVATE ${PYTHON_INCLUDE_DIRS})
endif()

# 安装规则
install(TARGETS cpp_exercise1_1 cpp_exercise1_2 cpp_exercise1_3 cpp_test1_1
        RUNTIME DESTINATION bin/${MODULE_NAME}
        LIBRARY DESTINATION lib/${MODULE_NAME}
        ARCHIVE DESTINATION lib/${MODULE_NAME}
) 