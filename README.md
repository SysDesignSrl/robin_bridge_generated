# robin_bridge_generated

## Overview
Shared memory bridge to map CODESYS variables to ROS topics and viceversa.

## Continuous Integration
| Branch   | Status                                                                                                                                                                                              |
|----------|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| pallcube |[![CI](https://github.com/SysDesignSrl/robin_bridge_generated/actions/workflows/ci.yaml/badge.svg?branch=pallcube)](https://github.com/SysDesignSrl/robin_bridge_generated/actions/workflows/ci.yaml)|

## Nodes
robin \
  _Node running the shared memory communication._

### Subscribed Topics
ROBOT_ID/diagnostics ([diagnostic_msgs/DiagnosticArray](http://docs.ros.org/en/noetic/api/diagnostic_msgs/html/msg/DiagnosticArray.html)) \
  _Robot diagnostics stream._

### Published Topics
ROBOT_ID/robin/run ([std_msgs/Bool](http://docs.ros.org/en/api/std_msgs/html/msg/Bool.html)) \
  _Enable task execution._

ROBOT_ID/robin/lft/palletizing_options ([robin_bridge_generated/PalletizingOptions](https://github.com/SysDesignSrl/robin_bridge_generated/blob/pallcube/msg/PalletizingOptions.msg)) \
  _The palletizing options for the left side._

ROBOT_ID/robin/rgt/palletizing_options ([robin_bridge_generated/PalletizingOptions](https://github.com/SysDesignSrl/robin_bridge_generated/blob/pallcube/msg/PalletizingOptions.msg)) \
  _The palletizing options for the right side._

### Process Code Topics
#### Subscribed
ROBOT_ID/robin/process_code ([std_msgs/Int32](http://docs.ros.org/en/api/std_msgs/html/msg/Int32.html)) \
  _A code representing the status of task execution._

#### Published
ROBOT_ID/robin/process_code_ack ([std_msgs/Int32](http://docs.ros.org/en/api/std_msgs/html/msg/Int32.html)) \
  _The acknowledge of the status of task execution._

<!-- 
### Semaphores Topics
#### Subscribed
ROBOT_ID/robin/picking/request ([std_msgs/Bool](http://docs.ros.org/en/api/std_msgs/html/msg/Bool.html)) \
  _Picking execution request._

#### Published
ROBOT_ID/robin/picking/consensus ([std_msgs/Bool](http://docs.ros.org/en/api/std_msgs/html/msg/Bool.html)) \
  _Picking execution consensus._ 
-->

### Lifter Topics
#### Subscribed
ROBOT_ID/robin/lifter_controller/command ([robin_bridge_generatd/CommonCommand](https://github.com/SysDesignSrl/robin_bridge_generated/blob/pallcube/msg/CommonCommand.msg)) \
  _Command to control the robot lifter._

#### Published
ROBOT_ID/robin/lifter_controller/feedback ([robin_bridge_generatd/CommonFeedback](https://github.com/SysDesignSrl/robin_bridge_generated/blob/pallcube/msg/CommonFeedback.msg)) \
  _Feedback from the robot lifter._

ROBOT_ID/robin/lifter_controller/joint_states ([sensor_msgs/JointState](http://docs.ros.org/en/api/sensor_msgs/html/msg/JointState.html)) \
  _The current joint state of the lifter representing it's height. [meters]_


_ROBOT_ID: The namespace grouping the topics belonging to each robot. Required to control multiple robots with ROS._