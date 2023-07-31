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
  RobinSubscriber<CommonCommand, robin_bridge_generated::CommonCommand> conveyor_1_command(nh, "conveyor_1_command");
  RobinSubscriber<CommonCommand, robin_bridge_generated::CommonCommand> conveyor_2_command(nh, "conveyor_2_command");
  RobinSubscriber<CameraMsg, robin_bridge_generated::CameraMsg> camera_msg(nh, "camera_msg");
  RobinPublisher<uint8_t, std_msgs::Bool> run(nh, "run");
  RobinPublisher<uint8_t, std_msgs::Bool> gripper_feedback(nh, "gripper_feedback");
  RobinPublisher<CommonFeedback, robin_bridge_generated::CommonFeedback> conveyor_1_feedback(nh, "conveyor_1_feedback");
  RobinPublisher<CommonFeedback, robin_bridge_generated::CommonFeedback> conveyor_2_feedback(nh, "conveyor_2_feedback");
  RobinPublisher<uint8_t, std_msgs::Bool> can_pick(nh, "can_pick");
  RobinPublisher<uint8_t, std_msgs::Bool> can_place(nh, "can_place");
  ROS_INFO("Robin node initiated...");
  ros::spin();
  return 0;
}
