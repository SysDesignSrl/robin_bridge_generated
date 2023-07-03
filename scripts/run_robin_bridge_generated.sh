#!/bin/bash

# Bash script for starting robin bridge generated node in ROS
# Script arguments:
# - restart_codesys: 0=NO RESTART  1=RESTART

# first check if rosmaster is already running
rosPid=`/bin/ps -fu $USER| grep "rosmaster" | grep -v "grep" | awk '{print $2}'`

if [ -z ${rosPid} ]; then

    echo "[INFO]: rosmaster is not running"

else

    echo "[INFO]: rosmaster is running on PID ${rosPid}"
    echo "[WARN]: killing rosmaster..."

    kill ${rosPid}

fi

restartCodesys=$1

echo
echo "[INFO]: sourcing setup bash"

source ~/ros/robin_ws/devel/setup.bash

echo "[INFO]: starting robin bridge generated"

roslaunch robin_bridge_generated run.launch restart_codesys:=${restartCodesys}