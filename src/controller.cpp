#include "include/micro_ros_async_controller/controller.hpp"
#include <chrono>
#include <functional>
using namespace std::chrono_literals;
ControllerNode::ControllerNode():Node("micro_ros_async_controller"),
linear_velocity_(0.0), 
angular_velocity_(0.0),
controller_active(true) {
  subscriber_group = this->create_callback_group(rclcpp::CallbackGroupType::MutuallyExclusive);
  service_group = this->create_callback_group(rclcpp::CallbackGroupType::Reentrant);
  status_publsher = this->create_publisher<std.msgs::msg::String>("/status", 10);

  rclcpp::SubcriptionOptions sub_options;
  sub_options.callback_group = subscriber_group_;
  cmd_vel_subscriber = 
    this->create_subscription<geometry_msgs::msg::Twist>("/cmd_vel, 10, 
    std::bind(
    &ControllerNode::cmdVelCallback, this, std::placeholders::_1),
    sub_options 
    );
  reset_service_ = this->create_service<std_srvs::svr::Trigger>(
    "/reset_controller",
    std::bind(
    &ControllerNode::resetServiceCallback,
    this,
    std::placeholders::_1
    std::placeholders::_2
    ),
    rmw_qos_profile_services_default,
    service_group_
    );
  timer_ = this->create_wall_timer(100ms, std::bind(&ControllerNode::timerCallback, this),
    timer_group);
  RCLCPP_INFO(this->getlogger(), "Micro-ROS Async Controller Started");
}
void ControllerNode::timerCallback()
{
  if (!controller_active_){
    return;
  }
  std_msgs::msg::String status_msg;
  status_msg.data = "Controller running | linear = " + std::to_string(linear_velocity_) + 
    "agnular = " + std::to_string(angular_veloity_);
  status_publisher_ -> publish(status_msg);
  RCLCPP_INFO(
  this->get_logger(),  "Publishing controller status"
  );
}
void ControllerNode:: :resetServiceCallback(
const std::shared_ptr<std_srvs::srv::Trigger::Request> request,
std::shared_ptr<std_srvs::srv::Trigger::Response> response)
{
  (void) request;
  linear_velocity_ = 0.0;
  angular_velocity_ = 0.0;
  controller_active_ = true;
  responce -> succes = true;
  responce -> message = "Controller state reset";
  RCLCPP_INFO(
  this->get_loogger(), "Controller reset completed"
  );
    
}

  
  
  )
    )
  )
    
  )")
}
  
