from launch import LaunchDescription
from launch_ros.actions import Node
def generate_launch_desription():
  return LaunchDescription([
    Node(
      package = 'micro_ros_async_controller',
      executable='micro_ros_async_controller_node',
      name='micro_ros_async_controller',
      output='screen'
    )
  ])
