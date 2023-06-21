#include <cstdio>   // for std::snprintf()
#include <cstring>  // for std::memcpy()
#include <robin_bridge/robin_publisher.hpp>
#include <robin_bridge/robin_subscriber.hpp>
#include <robin_bridge_generated/structs.h>
#include "robin_bridge_generated/CommonCommand.h"
#include "robin_bridge_generated/CommonFeedback.h"
#include "robin_bridge_generated/PalletizingOptions.h"
#include "sensor_msgs/JointState.h"
#include "std_msgs/Bool.h"
#include "std_msgs/Int32.h"
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
template class RobinPublisher<uint8_t, std_msgs::Bool>;
template class RobinPublisher<PalletizingOptions, robin_bridge_generated::PalletizingOptions>;
template class RobinPublisher<CommonFeedback, robin_bridge_generated::CommonFeedback>;
template class RobinPublisher<JointState, sensor_msgs::JointState>;
