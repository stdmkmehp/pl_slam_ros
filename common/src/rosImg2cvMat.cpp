#include "rosImg2cvMat.h"

extern cv::Mat leftIm;
extern cv::Mat rightIm;
extern cv::Mat leftCompressedIm;

cv::Mat matFromImage(const sensor_msgs::CompressedImageConstPtr& source)
{
	cv::Mat jpegData(1,source->data.size(),CV_8UC1);
	jpegData.data 	= const_cast<uchar*>(&source->data[0]);
	cv::InputArray data(jpegData);
	cv::Mat bgrMat 	= cv::imdecode(data,cv::IMREAD_COLOR);
	return bgrMat;
}

void leftImCallback(const sensor_msgs::ImageConstPtr& msg)
{
  try
  {
  	cv::resize(cv_bridge::toCvCopy(msg, "8UC3")->image, leftIm, cv::Size(640, 360));
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
  	cv::resize(cv_bridge::toCvCopy(msg, "8UC3")->image, rightIm, cv::Size(640, 360));
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
  	// leftCompressedIm = matFromImage(msg);
  	cv::resize(matFromImage(msg), leftCompressedIm, cv::Size(640, 360));
  	// ROS_INFO("leftCompressedImCallback");
  	// cv::imwrite("/home/lab404/Documents/leftCompressedIm.jpg",leftCompressedIm);
  }
  catch (cv_bridge::Exception& e)
  {
  	ROS_ERROR("Could not convert from leftCompressedIm to cvMat.");
  }
}