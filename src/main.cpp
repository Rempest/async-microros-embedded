#include <rclcpp/rclcpp.hpp>
#include "micro_ros_async_controller/controller.hpp"

int main(int argc, char ** argv)
{
    rclcpp::init(argc, argv);

    auto node = std::make_shared<ControllerNode>();

    rclcpp::executors::MultiThreadedExecutor executor;

    executor.add_node(node);

    RCLCPP_INFO(
        node->get_logger(),
        "Starting micro_ros_async_controller node..."
    );

    executor.spin();

    rclcpp::shutdown();

    return 0;
}
