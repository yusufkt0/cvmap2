#include <iostream>
#include <opencv4/opencv2/videoio.hpp>
#include <ostream>
#include "opencv2/opencv.hpp"
#include "opencv2/core/version.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/opencv.hpp"
#include "opencv2/videoio.hpp"

using namespace cv;
int main(){
    std::cout << CV_VERSION;
    VideoCapture cap;
    while (!cap.isOpened()){
        int n = 0;
        VideoCapture cap(n,CAP_V4L2);
        n+=1;
        if (n==5) {
            return 0;
        }
    }
    if(!cap.isOpened()){
        

    }
    namedWindow("window",WINDOW_NORMAL);

    while (true) {
        Mat frame;
        cap >> frame;
        if (frame.empty()) {
            std::cerr << "nggr" << std::endl;
            break;
        }
        Mat gray;
        cvtColor(frame, gray, COLOR_BGR2GRAY);
        Mat threshed;        
        adaptiveThreshold(gray, threshed, 255, cv::ADAPTIVE_THRESH_MEAN_C, cv::THRESH_BINARY, 11, 2);    
        imshow("n",frame);
        imshow("t",threshed);

        if (cv::waitKey(0) == 27) {
            break;
        }
    }
    cap.release();
    destroyAllWindows();

    return 0;
}