#include <opencv2/opencv.hpp>
#include <opencv2/tracking.hpp>
#include "tracker.h"
using namespace cv;

int main(){
	
	VideoCapture cap(0, CAP_V4L2);
	if(!cap.isOpened()){
		std::cerr << "Failed to open camera\n";
		return -1;
	}

	Mat frame;
	cap.set(CAP_PROP_FOURCC, VideoWriter::fourcc('M','J','P','G'));
	cap.set(cv::CAP_PROP_FRAME_WIDTH, 640);
	cap.set(cv::CAP_PROP_FRAME_HEIGHT, 480);



	if(!cap.read(frame) || frame.empty()){
		cap.release();
		return 0;
	}
	


	namedWindow("frame");

	ObjectTracker myTracker;

	if(!myTracker.init(frame)){
		cap.release();
		return 0;
	}

	while(true){
		cap.read(frame);
		if(frame.empty()) break;
		
		myTracker.update(frame);

		myTracker.draw(frame);
		
		
		int key = waitKey(1);

		if(key == 32){        
			if(!myTracker.init(frame))
				break;
		}
		if(key == 27) break;
	}
	cap.release();
	destroyAllWindows();

return 0;
}
