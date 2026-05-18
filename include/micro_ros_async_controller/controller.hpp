#indef MICRO_ROS_ASYNC_CONTROLLER_CONTROLLER_HPP
#define MICRO_ROS_ASYNC_CONTROLLER_CONTROLLER_HPP
#include <rclcpp/rclcpp.hpp>
#include <geometry_msgs/msg/twist.hpp>
#include <std_srvs/srv/trigger.hpp>
#include <memory>
#include <string>
class ControllerNode() : public rclcpp::Node{
  public:
  ControllerNode()
  private:
  void cmVelCallback(const geometry_msgs::msg::Twist::SharedPtr msg);
 void timer_callback();
 void resetServiceCallback(const std::shared_ptr<std_srvs::Trigger::Request? request>
 std::Shared_ptr<std_srvs::srv::Trigger::Response> response);
rclcpp::Publisher<std_msg::msg::String>::SharedPtr status_publisher_;
rclcpp::Subcription<geometry_msgs::msg::Twist>::SharedPtr cmd_vel_subscriber_;
rclcpp::Service<std_svrs::srv::Trigger>:SharedPtr reset_service_;
rclcpp::CallBackGroup::SharedPtr subscriber_group_;
rclcpp::CallBackGroup::SharedPtr service_group_;
rclcpp::CallBackGroup::SharedPtr timer_group_;
double linear_velocity_;
double angular_velocity_;
bool controller_activity_;
};
#endif



