#include <cstdio>   // for std::snprintf()
#include <cstring>  // for std::memcpy()
#include <robin_bridge/robin_publisher.hpp>
#include <robin_bridge/robin_subscriber.hpp>
#include <robin_bridge_generated/structs.h>
#include "diagnostic_msgs/DiagnosticArray.h"
#include "robin_bridge_generated/CommonCommand.h"
#include "robin_bridge_generated/CommonFeedback.h"
#include "robin_bridge_generated/PalletizingOptions.h"
#include "sensor_msgs/JointState.h"
#include "std_msgs/Bool.h"
#include "std_msgs/Int32.h"
template<> void RobinSubscriber<DiagnosticArray, diagnostic_msgs::DiagnosticArray>::write(diagnostic_msgs::DiagnosticArray const *msg_ptr)
{
  (*shm_ptr_).header.seq = (*msg_ptr).header.seq;
  // pod struct to pod struct
  std::memcpy(&((*shm_ptr_).header.stamp), &((*msg_ptr).header.stamp), sizeof((*shm_ptr_).header.stamp));
  // END pod struct to pod struct
  // std::string to char[]
  std::snprintf((*shm_ptr_).header.frame_id, sizeof((*shm_ptr_).header.frame_id), "%s", (*msg_ptr).header.frame_id.c_str());
  // END std::string to char[]
  // non-pod std::vector to array
  size_t shm_len_0 = sizeof((*shm_ptr_).status) / sizeof(DiagnosticStatus);
  size_t msg_len_0 = std::min((*msg_ptr).status.size(), shm_len_0);
  for (int i_0 = 0; i_0 < msg_len_0; i_0++)
  {
    (*shm_ptr_).status[i_0].level = (*msg_ptr).status[i_0].level;
    // std::string to char[]
    std::snprintf((*shm_ptr_).status[i_0].name, sizeof((*shm_ptr_).status[i_0].name), "%s", (*msg_ptr).status[i_0].name.c_str());
    // END std::string to char[]
    // std::string to char[]
    std::snprintf((*shm_ptr_).status[i_0].message, sizeof((*shm_ptr_).status[i_0].message), "%s", (*msg_ptr).status[i_0].message.c_str());
    // END std::string to char[]
    // std::string to char[]
    std::snprintf((*shm_ptr_).status[i_0].hardware_id, sizeof((*shm_ptr_).status[i_0].hardware_id), "%s", (*msg_ptr).status[i_0].hardware_id.c_str());
    // END std::string to char[]
    // non-pod std::vector to array
    size_t shm_len_0_0 = sizeof((*shm_ptr_).status[i_0].values) / sizeof(KeyValue);
    size_t msg_len_0_0 = std::min((*msg_ptr).status[i_0].values.size(), shm_len_0_0);
    for (int i_0_0 = 0; i_0_0 < msg_len_0_0; i_0_0++)
    {
      // std::string to char[]
      std::snprintf((*shm_ptr_).status[i_0].values[i_0_0].key, sizeof((*shm_ptr_).status[i_0].values[i_0_0].key), "%s", (*msg_ptr).status[i_0].values[i_0_0].key.c_str());
      // END std::string to char[]
      // std::string to char[]
      std::snprintf((*shm_ptr_).status[i_0].values[i_0_0].value, sizeof((*shm_ptr_).status[i_0].values[i_0_0].value), "%s", (*msg_ptr).status[i_0].values[i_0_0].value.c_str());
      // END std::string to char[]
    }
    zeroUnsentElements((*shm_ptr_).status[i_0].values, msg_len_0_0, shm_len_0_0);
    // END non-pod std::vector to array
  }
  zeroUnsentElements((*shm_ptr_).status, msg_len_0, shm_len_0);
  // END non-pod std::vector to array
}
template<> void RobinPublisher<PalletizingOptions, robin_bridge_generated::PalletizingOptions>::read()
{
  msg_.skip = (*shm_ptr_).skip;
  // char[] to std::string
  msg_.tool_name = (*shm_ptr_).tool_name;
  // END char[] to std::string
  msg_.skip_object = (*shm_ptr_).skip_object;
  // char[] to std::string
  msg_.object_name = (*shm_ptr_).object_name;
  // END char[] to std::string
  msg_.object_weight = (*shm_ptr_).object_weight;
  // char[] to std::string
  msg_.pattern_file = (*shm_ptr_).pattern_file;
  // END char[] to std::string
  // char[] to std::string
  msg_.transform_name = (*shm_ptr_).transform_name;
  // END char[] to std::string
  msg_.reload_pattern = (*shm_ptr_).reload_pattern;
  msg_.start_index = (*shm_ptr_).start_index;
}
template<> void RobinPublisher<JointState, sensor_msgs::JointState>::read()
{
  msg_.header.seq = (*shm_ptr_).header.seq;
  // pod struct to pod struct
  std::memcpy(&(msg_.header.stamp), &((*shm_ptr_).header.stamp), sizeof(msg_.header.stamp));
  // END pod struct to pod struct
  // char[] to std::string
  msg_.header.frame_id = (*shm_ptr_).header.frame_id;
  // END char[] to std::string
  // non-pod array to std::vector
  size_t shm_len_0 = sizeof((*shm_ptr_).name) / sizeof(char[81]);
  msg_.name.resize(shm_len_0);  //TODO execute only once, eg. in constructor
  for (int i_0 = 0; i_0 < shm_len_0; i_0++)
  {
    // char[] to std::string
    msg_.name[i_0] = (*shm_ptr_).name[i_0];
    // END char[] to std::string
  }
  // END non-pod array to std::vector
  // pod array to std::vector
  size_t const shm_len_1 = sizeof((*shm_ptr_).position) / sizeof(double);
  msg_.position.assign((*shm_ptr_).position, (*shm_ptr_).position + shm_len_1);
  // END pod array to std::vector
  // pod array to std::vector
  size_t const shm_len_2 = sizeof((*shm_ptr_).velocity) / sizeof(double);
  msg_.velocity.assign((*shm_ptr_).velocity, (*shm_ptr_).velocity + shm_len_2);
  // END pod array to std::vector
  // pod array to std::vector
  size_t const shm_len_3 = sizeof((*shm_ptr_).effort) / sizeof(double);
  msg_.effort.assign((*shm_ptr_).effort, (*shm_ptr_).effort + shm_len_3);
  // END pod array to std::vector
}
template class RobinSubscriber<int32_t, std_msgs::Int32>;
template class RobinSubscriber<CommonCommand, robin_bridge_generated::CommonCommand>;
template class RobinSubscriber<DiagnosticArray, diagnostic_msgs::DiagnosticArray>;
template class RobinPublisher<uint8_t, std_msgs::Bool>;
template class RobinPublisher<PalletizingOptions, robin_bridge_generated::PalletizingOptions>;
template class RobinPublisher<CommonFeedback, robin_bridge_generated::CommonFeedback>;
template class RobinPublisher<JointState, sensor_msgs::JointState>;
template class RobinPublisher<int32_t, std_msgs::Int32>;
