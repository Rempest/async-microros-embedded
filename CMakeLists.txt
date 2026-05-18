cmake_minimum_required(VERSION 3.8)
project(micro_ros_async_controller)

if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 17)
endif()

add_compile_options(-Wall -Wextra -Wpedantic)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(std_srvs REQUIRED)

include_directories(
  include
)

add_executable(micro_ros_async_controller_node
  src/main.cpp
  src/controller.cpp
)

ament_target_dependencies(micro_ros_async_controller_node
  rclcpp
  std_msgs
  geometry_msgs
  std_srvs
)

install(TARGETS
  micro_ros_async_controller_node
  DESTINATION lib/${PROJECT_NAME}
)

install(
  DIRECTORY include/
  DESTINATION include/
)

install(
  DIRECTORY launch
  DESTINATION share/${PROJECT_NAME}
)

install(
  DIRECTORY config
  DESTINATION share/${PROJECT_NAME}
)
ament_package()
