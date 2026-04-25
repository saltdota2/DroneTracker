#include "tracker.h"
#include <iostream>

ObjectTracker::ObjectTracker(){
	showCounter = 0;
	trackingActive = false;
}

bool ObjectTracker::init(cv::Mat& frame){
	bbox = cv::selectROI("frame", frame);
	if(bbox.width == 0 || bbox.height == 0){
		return false;
	}

	std::cout << bbox.x << " " << bbox.y << std::endl;

	tracker = cv::TrackerCSRT::create();
	tracker->init(frame, bbox);

	showCounter = 0;
	trackingActive = true;

	return true;
}

void ObjectTracker::update(cv::Mat& frame){
	if(!trackingActive) return;
	
	if(tracker->update(frame, bbox)){
		showCounter = 0;
		cv::rectangle(frame, bbox, cv::Scalar(0,255,0), 2);
		
		computeCoordinates(frame);
	}
	else{
		showCounter++;
		if(showCounter<300 && (showCounter % 20)<13){
			putText(frame,"Target lost", cv::Point(50,50), cv::FONT_HERSHEY_SIMPLEX, 1.0, cv::Scalar(0,0,255), 2);
		}
	}
}

void ObjectTracker::draw(cv::Mat& frame){
	cv::imshow("frame", frame);
}

void ObjectTracker::computeCoordinates(cv::Mat& frame){
	targetX = bbox.x + bbox.width / 2;
	targetY = bbox.y + bbox.height / 2;

	frameX = frame.cols / 2;
	frameY = frame.rows / 2;

	errorX = targetX - frameX;
	errorY = targetY - frameY;

	std::string text = "X:" +std::to_string(errorX) + " Y:" + std::to_string(errorY);
	
	int textY = std::max(20, bbox.y - 10);
	putText(frame, text, cv::Point(bbox.x,textY), cv::FONT_HERSHEY_SIMPLEX, 1.0, cv::Scalar(0,255,0), 2);
}

