#include <opencv2/opencv.hpp>
#include <opencv2/videoio.hpp>

int main() {
    // Open a video capture object (camera index 0 by default)
    cv::VideoCapture cap(0, cv::CAP_V4L2);

    // Check if the camera opened successfully
    if (!cap.isOpened()) {
        std::cerr << "Error: Could not open camera." << std::endl;
        return -1;
    }

    while (true) {
        cv::Mat frame;
        // Capture a frame from the camera
        cap >> frame;

        // Check if the frame is empty (end of video stream)
        if (frame.empty()) {
            std::cerr << "Error: Empty frame." << std::endl;
            break;
        }

        // Convert the frame to grayscale
        cv::Mat gray;
        cv::cvtColor(frame, gray, cv::COLOR_BGR2GRAY);

        // Apply adaptive thresholding with adjusted parameters
        cv::Mat thresholded;
        int blockSize = 15; // Adjust the blockSize parameter
        int C = 5;          // Adjust the C parameter
        cv::adaptiveThreshold(gray, thresholded, 255,
                              cv::ADAPTIVE_THRESH_MEAN_C, cv::THRESH_BINARY, blockSize, C);

        // Display the original and thresholded frames
        cv::imshow("Camera Feed", frame);
        cv::imshow("Adaptive Threshold", thresholded);

        // Check for the 'ESC' key to exit the loop
        if (cv::waitKey(1) == 'q') {
            break;
        }
    }

    // Release the video capture object and close windows
    cap.release();
    cv::destroyAllWindows();

    return 0;
}
