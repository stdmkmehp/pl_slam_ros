#pragma once

#include "ros/ros.h"

#include <sensor_msgs/Image.h>
#include <sensor_msgs/CompressedImage.h>

#include <opencv2/opencv.hpp>

#include <cv_bridge/cv_bridge.h>

extern cv::Mat leftIm;
extern cv::Mat rightIm;
// extern cv::Mat leftCompressedIm;
// extern cv::Mat rightCompressedIm;

cv::Mat matFromImage(const sensor_msgs::CompressedImageConstPtr& source)
{
	cv::Mat jpegData(1,source->data.size(),CV_8UC3);
	jpegData.data 	= const_cast<uchar*>(&source->data[0]);
	cv::InputArray data(jpegData);
	cv::Mat bgrMat 	= cv::imdecode(data,cv::IMREAD_COLOR);
	return bgrMat;
}

void leftImCallback(const sensor_msgs::ImageConstPtr& msg)
{
  try
  {
  	// cv::resize(cv_bridge::toCvCopy(msg, "8UC3")->image, leftIm, cv::Size(640, 360));
  	leftIm = cv_bridge::toCvCopy(msg, "8UC3")->image;
  	// ROS_INFO("leftIm");
  	// cv::imwrite("/home/lab404/Documents/leftIm.jpg",leftIm);
  }
  catch (cv_bridge::Exception& e)
  {
  	ROS_ERROR("Could not convert from '%s' to '8UC3'.", msg->encoding.c_str());
  }
}
void rightImCallback(const sensor_msgs::ImageConstPtr& msg)
{
  try
  {
  	// cv::resize(cv_bridge::toCvCopy(msg, "8UC3")->image, rightIm, cv::Size(640, 360));
  	rightIm = cv_bridge::toCvCopy(msg, "8UC3")->image;
  	// ROS_INFO("rightIm");
  	// cv::imwrite("/home/lab404/Documents/rightIm.jpg",rightIm);
  }
  catch (cv_bridge::Exception& e)
  {
  	ROS_ERROR("Could not convert from '%s' to '8UC3'.", msg->encoding.c_str());
  }
}

void leftCompressedImCallback(const sensor_msgs::CompressedImageConstPtr& msg)
{
  try
  {
  	// cv::resize(matFromImage(msg), leftIm, cv::Size(640, 360));
  	leftIm = matFromImage(msg);
  	// ROS_INFO("leftCompressedImCallback");
  	// cv::imwrite("/home/lab404/Documents/leftIm.jpg",leftIm);
  }
  catch (...)
  {
  	ROS_ERROR("Could not convert from leftCompressedIm to cvMat.");
  }
}
void rightCompressedImCallback(const sensor_msgs::CompressedImageConstPtr& msg)
{
  try
  {
    // cv::resize(matFromImage(msg), rightIm, cv::Size(640, 360));
    rightIm = matFromImage(msg);
    // ROS_INFO("leftCompressedImCallback");
    // cv::imwrite("/home/lab404/Documents/rightIm.jpg",rightIm);
  }
  catch (...)
  {
    ROS_ERROR("Could not convert from rightCompressedIm to cvMat.");
  }
}