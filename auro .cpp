#include <rclcpp/rclcpp.hpp>
#include "hardware_interface/hardware_info.hpp"
#include "hardware_interface/handle.hpp"
#include <geometry_msgs/msg/twist.hpp>
#include "FreeRTOS.h"
#include "task.h"
#include <stdio.h>
using namespace std;

// Control loop implementation
class ControlLoop : public rclcpp::Node
{
public:
  void control_loop(double linear, double angular)
  {
    //the real time task
    RTOStask(MyTask, "RTOStask", 1000, NULL, 1, NULL);
    static void MyTask(void *pvParameters) {
      // Task implementation
      for(;;){
        printf("RTOS is running");
        vTaskDelay(pdMS_TO_TICKS(1000));
      }
    }

    // Control loop implementation
    create_hardware_interface(linear, angular);
    create_subscribers();
    create_timer();
    create_publishers();
  }
public:
//create hardware interface
  void create_hardware_interface(double linear, double angular)
  {
    RCLCPP_INFO(this->get_logger(), "Creating hardware interface");
  }
//create motor
  void create_motor_interface(double linear, double angular)
  {
    RCLCPP_INFO(this->get_logger(), "Creating motor interface", linear, angular);
  }
// Create subscribers
  void create_subscribers()
  {
    RCLCPP_INFO(this->get_logger(), "Creating subscribers");
  }
// Create timer
  void create_timer()
  {
    RCLCPP_INFO(this->get_logger(), "Creating timer");
  }
// Create publishers
  void create_publishers()
  {
    RCLCPP_INFO(this->get_logger(), "Creating publishers");
  }
};
//the main function
int main (int argc, char **argv) {
  rclcpp::init(argc, argv);
  auto node = std::make_shared<ControlLoop>();
  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}
