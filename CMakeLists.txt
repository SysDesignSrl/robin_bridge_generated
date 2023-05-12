cmake_minimum_required(VERSION 2.8.3)
project(robin_bridge_generated)

add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  robin_bridge
  std_msgs
  message_generation
)


################################################
## Declare ROS messages, services and actions ##
################################################

add_message_files(
  FILES
  PalletizingOptions.msg
  CommonCommand.msg
  CommonFeedback.msg
  Header_.msg
  JointState.msg
)

generate_messages(
  DEPENDENCIES
  std_msgs
)


###################################
## catkin specific configuration ##
###################################

catkin_package(
  INCLUDE_DIRS include
  CATKIN_DEPENDS roscpp robin_bridge message_generation std_msgs message_runtime
)

###########
## Build ##
###########

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

add_library(robin_inst_generated src/${PROJECT_NAME}/robin_inst.cpp)
add_executable(robin_node_generated src/robin_node.cpp)

add_dependencies(robin_inst_generated ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
add_dependencies(robin_node_generated ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

target_link_libraries(robin_inst_generated
  ${catkin_LIBRARIES}
)

target_link_libraries(robin_node_generated
  ${catkin_LIBRARIES}
  robin_inst_generated
)

#############
## Install ##
#############

## Mark executables for installation
install(
  TARGETS robin_node_generated
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

## Mark libraries for installation
install(
  TARGETS robin_inst_generated
  ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  RUNTIME DESTINATION ${CATKIN_GLOBAL_BIN_DESTINATION}
)

## Mark cpp header files for installation
install(
  DIRECTORY include/${PROJECT_NAME}/
  DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
  FILES_MATCHING PATTERN "*.h"
)

## Mark other files for installation (e.g. launch and bag files, etc.)
install(DIRECTORY launch DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION})
