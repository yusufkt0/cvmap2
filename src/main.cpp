#include "main.hpp"
#include <iostream>
#include <opencv2/core/mat.hpp>
#include <opencv2/videoio.hpp>


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
    
    }


}