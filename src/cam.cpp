#include "cam.hpp"
#include "opencv2/opencv.hpp"
#include <opencv2/core/mat.hpp>
#include <opencv2/videoio.hpp>
#include <string>

int videoStream(int index, std::string backend){
    cv::VideoCapture cap(int index,std::string backend);
    cv::Mat frame;
    return 0;
}
