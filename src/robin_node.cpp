#include <ros/ros.h>
#include <ros/console.h>
#include "robin_bridge_generated/robin_inst.cpp"
int main(int argc, char **argv)
{
  ros::init(argc, argv, "robin");
  ros::NodeHandle nh("~");
  RobinSubscriber<int32_t, std_msgs::Int32> process_code_01(nh, "process_code_01");
  RobinSubscriber<int32_t, std_msgs::Int32> process_code_02(nh, "process_code_02");
  RobinSubscriber<CommonCommand, robin_bridge_generated::CommonCommand> lifter_controller_command_01(nh, "lifter_controller_command_01");
  RobinSubscriber<CommonCommand, robin_bridge_generated::CommonCommand> lifter_controller_command_02(nh, "lifter_controller_command_02");
  RobinPublisher<uint8_t, std_msgs::Bool> run_01(nh, "run_01");
  RobinPublisher<uint8_t, std_msgs::Bool> run_02(nh, "run_02");
  RobinPublisher<PalletizingOptions, robin_bridge_generated::PalletizingOptions> lft_palletizing_options_01(nh, "lft_palletizing_options_01");
  RobinPublisher<PalletizingOptions, robin_bridge_generated::PalletizingOptions> lft_palletizing_options_02(nh, "lft_palletizing_options_02");
  RobinPublisher<PalletizingOptions, robin_bridge_generated::PalletizingOptions> rgt_palletizing_options_01(nh, "rgt_palletizing_options_01");
  RobinPublisher<PalletizingOptions, robin_bridge_generated::PalletizingOptions> rgt_palletizing_options_02(nh, "rgt_palletizing_options_02");
  RobinPublisher<CommonFeedback, robin_bridge_generated::CommonFeedback> lifter_controller_feedback_01(nh, "lifter_controller_feedback_01");
  RobinPublisher<CommonFeedback, robin_bridge_generated::CommonFeedback> lifter_controller_feedback_02(nh, "lifter_controller_feedback_02");
  RobinPublisher<JointState, robin_bridge_generated::JointState> lifter_controller_joint_states_01(nh, "lifter_controller_joint_states_01");
  RobinPublisher<JointState, robin_bridge_generated::JointState> lifter_controller_joint_states_02(nh, "lifter_controller_joint_states_02");
  ROS_INFO("Robin node initiated...");
  ros::spin();
  return 0;
}
