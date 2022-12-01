#ifndef VISUALS_FACEDETECTOR_H
#define VISUALS_FACEDETECTOR_H
#include <opencv4/opencv2/dnn.hpp>
using namespace std;
using namespace cv;
using namespace dnn;

class FaceDetector
{
public:
    explicit FaceDetector();        // function which detect faces in an image frame
    vector<Rect> detect_face_rectangles(const Mat &frame);      //a vector containing data of detected faces

private:
    Net network_;
    const int input_image_width_;
    const int input_image_height_;
    const double scale_factor_;     //scale factor when creating image blob. Factor=1 usually.
    const Scalar mean_values_;      //Mean normalization values network was trained with
    const float confidence_threshold_;
};

#endif
