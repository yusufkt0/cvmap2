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
    VideoCapture cap(0, CAP_V4L2);
    if(!cap.isOpened()){
        std::cerr << "nto opned";
        return 0;

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