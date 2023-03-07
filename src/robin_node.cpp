#include <ros/ros.h>
#include <ros/console.h>
#include "robin_bridge_generated/robin_inst.cpp"
int main(int argc, char **argv)
{
  ros::init(argc, argv, "robin");
  ros::NodeHandle nh("~");
  RobinSubscriber<int32_t, std_msgs::Int32> process_code(nh, "process_code");
  RobinSubscriber<uint8_t, std_msgs::Bool> robot_run(nh, "robot_run");
  RobinSubscriber<uint8_t, std_msgs::Bool> gripper_command(nh, "gripper_command");
  RobinPublisher<uint8_t, std_msgs::Bool> run(nh, "run");
  RobinPublisher<uint8_t, std_msgs::Bool> gripper_feedback(nh, "gripper_feedback");
  ROS_INFO("Robin node initiated...");
  ros::spin();
  return 0;
}
