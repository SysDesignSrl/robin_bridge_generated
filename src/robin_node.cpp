#include <ros/ros.h>
#include <ros/console.h>
#include "robin_bridge_generated/robin_inst.cpp"
int main(int argc, char **argv)
{
  ros::init(argc, argv, "robin");
  ros::NodeHandle nh("~");
  RobinSubscriber<uint8_t, std_msgs::Bool> robot_run(nh, "robot_run");
  RobinSubscriber<uint8_t, std_msgs::Bool> find_bundle_done(nh, "find_bundle_done");
  RobinSubscriber<uint8_t, std_msgs::Bool> load_bundle_done(nh, "load_bundle_done");
  RobinSubscriber<uint8_t, std_msgs::Bool> feed_senzani_done(nh, "feed_senzani_done");
  RobinSubscriber<CommonCommand, robin_bridge_generated::CommonCommand> gripper_command(nh, "gripper_command");
  RobinSubscriber<CommonCommand, robin_bridge_generated::CommonCommand> stripper_command(nh, "stripper_command");
  RobinSubscriber<CommonCommand, robin_bridge_generated::CommonCommand> vacuum_command(nh, "vacuum_command");
  RobinPublisher<uint8_t, std_msgs::Bool> run(nh, "run");
  RobinPublisher<uint8_t, std_msgs::Bool> reset(nh, "reset");
  RobinPublisher<uint8_t, std_msgs::Bool> find_bundle(nh, "find_bundle");
  RobinPublisher<uint8_t, std_msgs::Bool> load_bundle(nh, "load_bundle");
  RobinPublisher<uint8_t, std_msgs::Bool> feed_senzani(nh, "feed_senzani");
  RobinPublisher<CommonFeedback, robin_bridge_generated::CommonFeedback> gripper_feedback(nh, "gripper_feedback");
  RobinPublisher<CommonFeedback, robin_bridge_generated::CommonFeedback> stripper_feedback(nh, "stripper_feedback");
  RobinPublisher<CommonFeedback, robin_bridge_generated::CommonFeedback> vacuum_feedback(nh, "vacuum_feedback");
  RobinPublisher<Pose, geometry_msgs::Pose> geek_pose(nh, "geek_pose");
  ROS_INFO("Robin node initiated...");
  ros::spin();
  return 0;
}
