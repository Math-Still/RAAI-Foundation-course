# 算法与数据结构模块
set(MODULE_NAME "AlgorithmDatastructure")

# 基础数据结构库
add_library(datastructures STATIC
    data_structures/vector.cpp
    data_structures/list.cpp
    data_structures/tree.cpp
    data_structures/graph.cpp
)

target_include_directories(datastructures PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# 算法库
add_library(algorithms STATIC
    algorithms/sorting.cpp
    algorithms/searching.cpp
    algorithms/graph_algorithms.cpp
    algorithms/dynamic_programming.cpp
)

target_include_directories(algorithms PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(algorithms datastructures)

# 测试程序
add_executable(algorithm_tests
    tests/test_sorting.cpp
    tests/test_searching.cpp
    tests/test_graph.cpp
)

target_link_libraries(algorithm_tests algorithms datastructures)

# 示例程序
add_executable(algorithm_examples
    examples/sorting_example.cpp
    examples/graph_example.cpp
    examples/dp_example.cpp
)

target_link_libraries(algorithm_examples algorithms datastructures)

# 添加测试
add_test(NAME algorithm_tests COMMAND algorithm_tests)
add_test(NAME algorithm_examples COMMAND algorithm_examples)

# 安装规则
install(TARGETS datastructures algorithms algorithm_tests algorithm_examples
        RUNTIME DESTINATION bin/${MODULE_NAME}
        LIBRARY DESTINATION lib/${MODULE_NAME}
        ARCHIVE DESTINATION lib/${MODULE_NAME}
)

install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/
        DESTINATION include/${MODULE_NAME}
        FILES_MATCHING PATTERN "*.h" PATTERN "*.hpp") 