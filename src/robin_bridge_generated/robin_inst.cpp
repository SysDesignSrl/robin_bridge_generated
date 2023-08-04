#include <cstdio>   // for std::snprintf()
#include <cstring>  // for std::memcpy()
#include <robin_bridge/robin_publisher.hpp>
#include <robin_bridge/robin_subscriber.hpp>
#include <robin_bridge_generated/structs.h>
#include "robin_bridge_generated/CameraMsg.h"
#include "robin_bridge_generated/CommonCommand.h"
#include "robin_bridge_generated/CommonFeedback.h"
#include "robin_bridge_generated/PlcMsg.h"
#include "std_msgs/Bool.h"
#include "std_msgs/Int32.h"
template<> void RobinSubscriber<CameraMsg, robin_bridge_generated::CameraMsg>::write(robin_bridge_generated::CameraMsg const *msg_ptr)
{
  (*shm_ptr_).header.seq = (*msg_ptr).header.seq;
  // pod struct to pod struct
  std::memcpy(&((*shm_ptr_).header.stamp), &((*msg_ptr).header.stamp), sizeof((*shm_ptr_).header.stamp));
  // END pod struct to pod struct
  // std::string to char[]
  std::snprintf((*shm_ptr_).header.frame_id, sizeof((*shm_ptr_).header.frame_id), "%s", (*msg_ptr).header.frame_id.c_str());
  // END std::string to char[]
  (*shm_ptr_).n_detections = (*msg_ptr).n_detections;
  (*shm_ptr_).suggested_step = (*msg_ptr).suggested_step;
}
template<> void RobinPublisher<PlcMsg, robin_bridge_generated::PlcMsg>::read()
{
  msg_.header.seq = (*shm_ptr_).header.seq;
  // pod struct to pod struct
  std::memcpy(&(msg_.header.stamp), &((*shm_ptr_).header.stamp), sizeof(msg_.header.stamp));
  // END pod struct to pod struct
  // char[] to std::string
  msg_.header.frame_id = (*shm_ptr_).header.frame_id;
  // END char[] to std::string
  msg_.tube_detected = (*shm_ptr_).tube_detected;
}
template class RobinSubscriber<int32_t, std_msgs::Int32>;
template class RobinSubscriber<uint8_t, std_msgs::Bool>;
template class RobinSubscriber<CommonCommand, robin_bridge_generated::CommonCommand>;
template class RobinSubscriber<CameraMsg, robin_bridge_generated::CameraMsg>;
template class RobinPublisher<uint8_t, std_msgs::Bool>;
template class RobinPublisher<CommonFeedback, robin_bridge_generated::CommonFeedback>;
template class RobinPublisher<PlcMsg, robin_bridge_generated::PlcMsg>;
