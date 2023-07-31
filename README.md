# robin_bridge_generated

## Overview
Shared memory bridge to map CODESYS variables to ROS topics and viceversa.

## Nodes
robin \
  _Node running the shared memory communication._

### Subscribed Topics
~process_code ([std_msgs/Int32](http://docs.ros.org/en/api/std_msgs/html/msg/Int32.html)) \
  _A code representing the status of task execution._

### Published Topics
~run ([std_msgs/Bool](http://docs.ros.org/en/api/std_msgs/html/msg/Bool.html)) \
  _Enable robot task execution._

~can_pick ([std_msgs/Bool](http://docs.ros.org/en/api/std_msgs/html/msg/Bool.html)) \
  _Allow pick execution._

~can_place ([std_msgs/Bool](http://docs.ros.org/en/api/std_msgs/html/msg/Bool.html)) \
  _Allow place execution._

### Gripper Topics
#### Subscribed
~gripper_command ([std_msgs/Bool](http://docs.ros.org/en/api/std_msgs/html/msg/Bool.html)) \
  _The signal to control the gripper._

#### Published
~gripper_feedback ([std_msgs/Bool](http://docs.ros.org/en/api/std_msgs/html/msg/Bool.html)) \
  _The feedback signal from the gripper._

### Conveyor Topics
#### Subscribed
~conveyor_1_command ([robin_bridge_generatd/CommonCommand](https://github.com/SysDesignSrl/robin_bridge_generated/blob/brooks/msg/CommonCommand.msg)) \
  _Command to control the conveyor 1._

~conveyor_2_command ([robin_bridge_generatd/CommonCommand](https://github.com/SysDesignSrl/robin_bridge_generated/blob/brooks/msg/CommonCommand.msg)) \
  _Command to control the conveyor 2._

#### Published
~conveyor_1_feedback ([robin_bridge_generatd/CommonFeedback](https://github.com/SysDesignSrl/robin_bridge_generated/blob/brooks/msg/CommonFeedback.msg)) \
  _Feedback from the conveyor 1._

~conveyor_2_feedback ([robin_bridge_generatd/CommonFeedback](https://github.com/SysDesignSrl/robin_bridge_generated/blob/brooks/msg/CommonFeedback.msg)) \
  _Feedback from the conveyor 2._

### Camera Topics
#### Subscribed
~camera_msg ([robin_bridge_generatd/CameraMsg](https://github.com/SysDesignSrl/robin_bridge_generated/blob/brooks/msg/CameraMsg.msg)) \
  _Info message from camera_