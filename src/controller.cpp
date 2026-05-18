#include "include/micro_ros_async_controller/controller.hpp"
#include <chrono>
#include <functional>
using namespace std::chrono_literals;
ControllerNode::ControllerNode():Node("micro_ros_async_controller"),
linear_velocity_(0.0), 
angular_velocity_(0.0),
controller_activity(true) {
  
}
  
