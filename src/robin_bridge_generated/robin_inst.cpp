#include <cstdio>   // for std::snprintf()
#include <cstring>  // for std::memcpy()
#include <robin_bridge/robin_publisher.hpp>
#include <robin_bridge/robin_subscriber.hpp>
#include <robin_bridge_generated/structs.h>
#include "std_msgs/Bool.h"
#include "std_msgs/Int32.h"
#include "std_msgs/String.h"
template<> void RobinPublisher<char[81], std_msgs::String>::read()
{
  // char[] to std::string
  msg_.data = (*shm_ptr_);
  // END char[] to std::string
}
template class RobinSubscriber<int32_t, std_msgs::Int32>;
template class RobinSubscriber<uint8_t, std_msgs::Bool>;
template class RobinPublisher<uint8_t, std_msgs::Bool>;
template class RobinPublisher<char[81], std_msgs::String>;
