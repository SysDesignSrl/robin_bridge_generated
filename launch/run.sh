#!/bin/bash

restartCodesys=$1

echo "[ INFO]: Force Codesyscontrol restart: ${restartCodesys}"

if [ $restartCodesys -eq 1 ]; then
    echo
    echo "[ INFO]: Stopping codesyscontrol service ... Trying with systemctl"
    sudo systemctl stop codesyscontrol
    if [ $? -eq 0 ]; then
        echo
        echo "[ INFO]: Starting codesyscontrol service via systemctl"
        sudo systemctl start codesyscontrol
    else
        echo
        echo "[ INFO]: Stopping codesyscontrol service ... Trying with service"
        sudo service codesyscontrol stop
        echo
        echo "[ INFO]: Starting codesyscontrol service via service"
        sudo service codesyscontrol start
    fi
    sleep 10
fi

if [ $? -eq 0 ]; then
    echo
    echo "[ INFO]: Starting robin bridge ..."
    echo
    roslaunch robin_bridge_generated robin_node_generated.launch
else
    echo
    echo "[ ERROR]: restarting codesyscontrol service"
fi