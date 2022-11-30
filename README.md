“Computer vision and machine learning have really started to take off, but for most people, the whole idea of what a computer is seeing when it’s looking at an image is relatively obscure.” – Mike Kreiger

In this project I have built a model which detects the face in video from webcam in realtime. I have built the project on C++ and opencv4. The versions used for cmake and openCV are 3.25.0 and 4.5.5 respectively. Using a pre-trained caffe model, it detects your face and draw a rectangle around it to indicate the face.

Lets dive into the code:

This line sets the video source to the default webcam, which OpenCV can easily capture.
```
video_capture = cv2.VideoCapture(0)
```
