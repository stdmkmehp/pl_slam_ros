cmake_minimum_required(VERSION 2.8.3)
project(pl_slam_ros)

## Find catkin and any catkin packages
#find_package(catkin REQUIRED COMPONENTS roscpp rospy std_msgs genmsg)
find_package(catkin REQUIRED COMPONENTS roscpp rospy std_msgs cv_bridge)

## Declare ROS messages and services
#add_message_files(FILES Num.msg)
#add_service_files(FILES AddTwoInts.srv)

## Generate added messages and services
#generate_messages(DEPENDENCIES std_msgs)

## Declare a catkin package
catkin_package()

include_directories(include ${catkin_INCLUDE_DIRS} ${PROJECT_SOURCE_DIR}/common/include/)

#set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/common/lib/)
#message("LIBRARY_OUTPUT_PATH = ${LIBRARY_OUTPUT_PATH}!!!!!!!!!!!!")
#aux_source_directory(${PROJECT_SOURCE_DIR}/common/src/ commonsources)
#add_library(common SHARED  ${commonsources})
#target_link_libraries( common ${catkin_LIBRARIES} ${OpenCV_LIBS} )

#list(APPEND LINK_LIBS libcommon.so)

add_subdirectory(stvo-pl)
add_subdirectory(pl-slam)
