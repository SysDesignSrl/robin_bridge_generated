#include <cstdio>   // for std::snprintf()
#include <cstring>  // for std::memcpy()
#include <robin_bridge/robin_publisher.hpp>
#include <robin_bridge/robin_subscriber.hpp>
#include <robin_bridge_generated/structs.h>
#include "geometry_msgs/Pose.h"
#include "robin_bridge_generated/CommonCommand.h"
#include "robin_bridge_generated/CommonFeedback.h"
#include "std_msgs/Bool.h"
template class RobinSubscriber<uint8_t, std_msgs::Bool>;
template class RobinSubscriber<CommonCommand, robin_bridge_generated::CommonCommand>;
template class RobinPublisher<uint8_t, std_msgs::Bool>;
template class RobinPublisher<CommonFeedback, robin_bridge_generated::CommonFeedback>;
template class RobinPublisher<Pose, geometry_msgs::Pose>;
