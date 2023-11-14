#include <ros/ros.h>
#include <ros/console.h>
#include "robin_bridge_generated/robin_inst.cpp"
int main(int argc, char **argv)
{
  ros::init(argc, argv, "robin");
  ros::NodeHandle nh("~");
  RobinSubscriber<uint8_t, std_msgs::Bool> robot_run(nh, "robot_run");
  RobinSubscriber<int32_t, std_msgs::Int32> process_code(nh, "process_code");
  RobinSubscriber<CommonCommand, robin_bridge_generated::CommonCommand> gripper_command(nh, "gripper_command");
  RobinSubscriber<CommonCommand, robin_bridge_generated::CommonCommand> stripper_command(nh, "stripper_command");
  RobinSubscriber<CommonCommand, robin_bridge_generated::CommonCommand> vacuum_command(nh, "vacuum_command");
  RobinSubscriber<int32_t, std_msgs::Int32> current_layer(nh, "current_layer");
  RobinPublisher<uint8_t, std_msgs::Bool> run(nh, "run");
  RobinPublisher<uint8_t, std_msgs::Bool> init_gripper(nh, "init_gripper");
  RobinPublisher<uint8_t, std_msgs::Bool> init_stripper(nh, "init_stripper");
  RobinPublisher<uint8_t, std_msgs::Bool> find_bundle(nh, "find_bundle");
  RobinPublisher<uint8_t, std_msgs::Bool> load_bundle(nh, "load_bundle");
  RobinPublisher<uint8_t, std_msgs::Bool> feed_senzani(nh, "feed_senzani");
  RobinPublisher<uint8_t, std_msgs::Bool> remove_strip(nh, "remove_strip");
  RobinPublisher<CommonFeedback, robin_bridge_generated::CommonFeedback> gripper_feedback(nh, "gripper_feedback");
  RobinPublisher<CommonFeedback, robin_bridge_generated::CommonFeedback> stripper_feedback(nh, "stripper_feedback");
  RobinPublisher<CommonFeedback, robin_bridge_generated::CommonFeedback> vacuum_feedback(nh, "vacuum_feedback");
  RobinPublisher<char[81], std_msgs::String> bundle_code(nh, "bundle_code");
  ROS_INFO("Robin node initiated...");
  ros::spin();
  return 0;
}
