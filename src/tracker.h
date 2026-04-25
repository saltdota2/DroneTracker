#pragma once


#include <opencv2/opencv.hpp>
#include <opencv2/tracking.hpp>


class ObjectTracker{
private:
	cv::Ptr<cv::Tracker> tracker;
	cv::Rect bbox;
	bool trackingActive;
	int showCounter;
	int frameX, frameY, targetX, targetY, errorX, errorY;

	void computeCoordinates(cv::Mat& frame);
public:
	ObjectTracker();
	bool init(cv::Mat& frame);
	void update(cv::Mat& frame);
	void draw(cv::Mat& frame);
};
