# 线性代数模块
set(MODULE_NAME "LinearAlgebra")

# 查找BLAS和LAPACK库
find_package(BLAS REQUIRED)
find_package(LAPACK REQUIRED)

# 线性代数核心库
add_library(linear_algebra STATIC
    core/matrix.cpp
    core/vector.cpp
    core/eigenvalues.cpp
    core/svd.cpp
    core/lu_decomposition.cpp
)

target_include_directories(linear_algebra PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(linear_algebra ${BLAS_LIBRARIES} ${LAPACK_LIBRARIES})

# 几何变换库
add_library(geometry STATIC
    geometry/rotation.cpp
    geometry/transformation.cpp
    geometry/quaternion.cpp
)

target_include_directories(geometry PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(geometry linear_algebra)

# 测试程序
add_executable(linear_algebra_tests
    tests/test_matrix.cpp
    tests/test_vector.cpp
    tests/test_eigenvalues.cpp
    tests/test_geometry.cpp
)

target_link_libraries(linear_algebra_tests linear_algebra geometry)

# 示例程序
add_executable(linear_algebra_examples
    examples/matrix_operations.cpp
    examples/eigenvalue_example.cpp
    examples/geometry_example.cpp
)

target_link_libraries(linear_algebra_examples linear_algebra geometry)

# 添加测试
add_test(NAME linear_algebra_tests COMMAND linear_algebra_tests)
add_test(NAME linear_algebra_examples COMMAND linear_algebra_examples)

# 安装规则
install(TARGETS linear_algebra geometry linear_algebra_tests linear_algebra_examples
        RUNTIME DESTINATION bin/${MODULE_NAME}
        LIBRARY DESTINATION lib/${MODULE_NAME}
        ARCHIVE DESTINATION lib/${MODULE_NAME}
)

install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/
        DESTINATION include/${MODULE_NAME}
        FILES_MATCHING PATTERN "*.h" PATTERN "*.hpp") 