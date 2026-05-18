#ifndef MICRO_ROS_ASYNC_CONTROLLER_CONTROLLER_HPP_
#define MICRO_ROS_ASYNC_CONTROLLER_CONTROLLER_HPP_
#include <rclcpp/rclcpp.hpp>
#include <geometry_msgs/msg/twist.hpp>
#include <std_msgs/msg/string.hpp>
#include <std_srvs/srv/trigger.hpp>
#include <memory>
#include <string>

class ControllerNode : public rclcpp::Node
{
public:
    ControllerNode();

private:
    void cmdVelCallback(
        const geometry_msgs::msg::Twist::SharedPtr msg
    );

    void timerCallback();

    void resetServiceCallback(
        const std::shared_ptr<std_srvs::srv::Trigger::Request> request,
        std::shared_ptr<std_srvs::srv::Trigger::Response> response
    );

    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr status_publisher_;

    rclcpp::Subscription<geometry_msgs::msg::Twist>::SharedPtr cmd_vel_subscriber_;

    rclcpp::Service<std_srvs::srv::Trigger>::SharedPtr reset_service_;

    rclcpp::TimerBase::SharedPtr timer_;

    rclcpp::CallbackGroup::SharedPtr subscriber_group_;

    rclcpp::CallbackGroup::SharedPtr service_group_;

    rclcpp::CallbackGroup::SharedPtr timer_group_;

    double linear_velocity_;

    double angular_velocity_;

    bool controller_active_;
};

#endif



