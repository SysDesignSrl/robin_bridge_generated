#include <ros/ros.h>
#include <ros/console.h>
#include "robin_bridge_generated/robin_inst.cpp"
int main(int argc, char **argv)
{
  ros::init(argc, argv, "robin");
  ros::NodeHandle nh("~");
  RobinSubscriber<int32_t, std_msgs::Int32> gripper_command(nh, "gripper_command");
  RobinSubscriber<uint8_t, std_msgs::Bool> robot_run(nh, "robot_run");
  RobinSubscriber<CommonCommand, robin_bridge_generated::CommonCommand> command(nh, "command");
  RobinPublisher<uint8_t, std_msgs::Bool> run(nh, "run");
  RobinPublisher<int32_t, std_msgs::Int32> gripper_feedback(nh, "gripper_feedback");
  RobinPublisher<uint8_t, std_msgs::Bool> reset(nh, "reset");
  RobinPublisher<CommonFeedback, robin_bridge_generated::CommonFeedback> feedback(nh, "feedback");
  ROS_INFO("Robin node initiated...");
  ros::spin();
  return 0;
}
