#include <ros/ros.h>
#include <ros/console.h>
#include "robin_bridge_generated/robin_inst.cpp"
int main(int argc, char **argv)
{
  ros::init(argc, argv, "robin");
  ros::NodeHandle nh("~");
  RobinSubscriber<int32_t, std_msgs::Int32> process_code_01(nh, "process_code_01");
  RobinSubscriber<int32_t, std_msgs::Int32> process_code_02(nh, "process_code_02");
  RobinSubscriber<uint8_t, std_msgs::Bool> robot_run_01(nh, "robot_run_01");
  RobinSubscriber<uint8_t, std_msgs::Bool> robot_run_02(nh, "robot_run_02");
  RobinPublisher<uint8_t, std_msgs::Bool> run_01(nh, "run_01");
  RobinPublisher<uint8_t, std_msgs::Bool> run_02(nh, "run_02");
  RobinPublisher<char[81], std_msgs::String> object_code_01(nh, "object_code_01");
  RobinPublisher<char[81], std_msgs::String> object_code_02(nh, "object_code_02");
  ROS_INFO("Robin node initiated...");
  ros::spin();
  return 0;
}
