#include "main.hpp"
#include <iostream>
#include <opencv2/core/mat.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/opencv_modules.hpp>


int main(){
    cv::VideoCapture cap(0,cv::CAP_V4L2);
    
    if(!cap.isOpened()){
        std::cerr << "cam not opened";
    }
    cv::Mat frame;
    while (true) {
        cap >> frame;
        if (frame.empty()) {
            std::cerr << "frame empty";
        
        }
        cv::Mat gray;
        cv::Mat thres;
        cv::Mat canny;

        cv::cvtColor(frame, gray , cv::COLOR_BGR2GRAY);
        cv::adaptiveThreshold(gray, thres, 20, cv::ADAPTIVE_THRESH_MEAN_C, cv::THRESH_BINARY,11, 4);
        cv::Canny(thres,canny,50,128);

            
        cv::imshow("",thres);

        if (cv::waitKey(1)=='q') {break;}
    }
    cap.release();
    cv::destroyAllWindows();


}