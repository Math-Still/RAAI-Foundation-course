# 机器人学模块
set(MODULE_NAME "Robotics")

# 查找依赖库
find_package(Eigen3 REQUIRED)
find_package(OpenCV REQUIRED)

# 运动学库
add_library(kinematics STATIC
    kinematics/forward_kinematics.cpp
    kinematics/inverse_kinematics.cpp
    kinematics/jacobian.cpp
    kinematics/dh_parameters.cpp
)

target_include_directories(kinematics PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(kinematics Eigen3::Eigen)

# 动力学库
add_library(dynamics STATIC
    dynamics/lagrangian.cpp
    dynamics/newton_euler.cpp
    dynamics/joint_torques.cpp
    dynamics/mass_matrix.cpp
)

target_include_directories(dynamics PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(dynamics kinematics Eigen3::Eigen)

# 控制库
add_library(control STATIC
    control/pid_controller.cpp
    control/computed_torque.cpp
    control/adaptive_control.cpp
    control/trajectory_planning.cpp
)

target_include_directories(control PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(control dynamics kinematics Eigen3::Eigen)

# 感知库
add_library(perception STATIC
    perception/image_processing.cpp
    perception/feature_detection.cpp
    perception/object_recognition.cpp
    perception/pose_estimation.cpp
)

target_include_directories(perception PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(perception ${OpenCV_LIBS})

# 测试程序
add_executable(robotics_tests
    tests/test_kinematics.cpp
    tests/test_dynamics.cpp
    tests/test_control.cpp
    tests/test_perception.cpp
)

target_link_libraries(robotics_tests kinematics dynamics control perception)

# 示例程序
add_executable(robotics_examples
    examples/robot_simulation.cpp
    examples/control_demo.cpp
    examples/vision_demo.cpp
)

target_link_libraries(robotics_examples kinematics dynamics control perception)

# 添加测试
add_test(NAME robotics_tests COMMAND robotics_tests)
add_test(NAME robotics_examples COMMAND robotics_examples)

# 安装规则
install(TARGETS kinematics dynamics control perception robotics_tests robotics_examples
        RUNTIME DESTINATION bin/${MODULE_NAME}
        LIBRARY DESTINATION lib/${MODULE_NAME}
        ARCHIVE DESTINATION lib/${MODULE_NAME}
)

install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/
        DESTINATION include/${MODULE_NAME}
        FILES_MATCHING PATTERN "*.h" PATTERN "*.hpp") 