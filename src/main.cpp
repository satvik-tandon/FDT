#include <opencv4/opencv2/opencv.hpp>
#include "FaceDetector.h"
using namespace cv;
using namespace std;
using namespace dnn;

int main()
{
    VideoCapture video_capture;
    if (!video_capture.open(0))
        return 0;

    FaceDetector face_detector;
    Mat frame;
    
    while (true)
    {
        video_capture >> frame;
        auto rectangles = face_detector.detect_face_rectangles(frame);
        Scalar color(0, 105, 205);
        for (const auto &r : rectangles)
            rectangle(frame, r, color, 4);

        imshow("Image", frame);
        int esc_key = 27;
        if (waitKey(10) == esc_key)
            break;
    }

    destroyAllWindows();
    video_capture.release();

    return 0;
}
