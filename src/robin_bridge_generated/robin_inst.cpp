#include <cstdio>   // for std::snprintf()
#include <cstring>  // for std::memcpy()
#include <robin_bridge/robin_publisher.hpp>
#include <robin_bridge/robin_subscriber.hpp>
#include <robin_bridge_generated/structs.h>
#include "robin_bridge_generated/CommonCommand.h"
#include "robin_bridge_generated/CommonFeedback.h"
#include "std_msgs/Bool.h"
#include "std_msgs/Int32.h"
template class RobinSubscriber<int32_t, std_msgs::Int32>;
template class RobinSubscriber<uint8_t, std_msgs::Bool>;
template class RobinSubscriber<CommonCommand, robin_bridge_generated::CommonCommand>;
template class RobinPublisher<uint8_t, std_msgs::Bool>;
template class RobinPublisher<int32_t, std_msgs::Int32>;
template class RobinPublisher<CommonFeedback, robin_bridge_generated::CommonFeedback>;
