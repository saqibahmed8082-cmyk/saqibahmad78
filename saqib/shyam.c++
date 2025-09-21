#include <stdio.h>
#include <opencv2/opencv.hpp>

int main() {
    cv::VideoCapture cap(0); // Open the default camera (webcam)
    if (!cap.isOpened()) {
        printf("Error: Could not open webcam\n");
        return -1;
    }

    cv::Mat frame;
    printf("Press ESC to exit...\n");
    while (1) {
        cap >> frame; // Capture a new frame
        if (frame.empty()) {
            printf("Error: Blank frame grabbed\n");
            break;
        }
        cv::imshow("Webcam", frame);
        if (cv::waitKey(30) == 27) { // Exit on ESC key
            break;
        }
    }
    cap.release();
    cv::destroyAllWindows();
    return 0;
}