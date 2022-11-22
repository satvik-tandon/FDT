#ifndef VISUALS_FACEDETECTOR_H
#define VISUALS_FACEDETECTOR_H
#include <opencv2/dnn.hpp>
using namespace std;
using namespace cv;
using namespace dnn;
// C:\Users\SATVIK66\FDT\CMakeLists.txt
class FaceDetector
{
public:
    explicit FaceDetector();
    vector<Rect> detect_face_rectangles(const Mat &frame);

private:
    Net network_;
    const int input_image_width_;
    const int input_image_height_;
    const double scale_factor_;
    const Scalar mean_values_;
    const float confidence_threshold_;
};

#endif
