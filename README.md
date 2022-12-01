![facial-recognition-system-concept-with-face-recognition-3d-scanning-interface](https://user-images.githubusercontent.com/67956852/205024405-d3be0328-f840-4866-aa96-e5bdb17d4fa6.jpg)





#### “Computer vision and machine learning have really started to take off, but for most people, the whole idea of what a computer is seeing when it’s looking at an image is relatively obscure.” – Mike Kreiger ####

In this project I have built a model which detects the face in video from webcam in realtime. I have built the project on C++ and opencv4. The versions used for CMake and openCV are 3.25.0 and 4.2.0 respectively. Using a pre-trained caffe model, it detects your face and draw a rectangle around it to indicate the face.



## Installing OpenCV

I have used parts of OpenCV and its OpenCV_contrib module. The most convenient way is by building OpenCV from source. I have used OpenCV version 4.2.0 on Ubuntu 22.04.

Step 1. Install OpenCV Dependencies and Build Tools
```shell
sudo apt install build-essential cmake git pkg-config libgtk-3-dev libavcodec-dev libavformat-dev libswscale-dev libv4l-dev libxvidcore-dev libx264-dev libjpeg-dev libpng-dev libtiff-dev gfortran openexr libatlas-base-dev python3-dev python3-numpy libtbb2 libtbb-dev libdc1394-dev libopenexr-dev libgstreamer-plugins-base1.0-dev libgstreamer1.0-dev -y
```
Step 2. Clone OpenCV and Its Repositories
```
mkdir -p opencv_build && cd ~/opencv_build
git clone https://github.com/opencv/opencv.git
git clone https://github.com/opencv/opencv_contrib.git
```
Step 3: Create a Build Directory
```
cd ~/opencv_build/opencv
mkdir -p build && cd build
cmake -D CMAKE_BUILD_TYPE=RELEASE CMAKE_INSTALL_PREFIX=/usr/local INSTALL_C_EXAMPLES=ON INSTALL_PYTHON_EXAMPLES=ON OPENCV_GENERATE_PKGCONFIG=ON OPENCV_EXTRA_MODULES_PATH=~/opencv_build/opencv_contrib/modules BUILD_EXAMPLES=ON ..
```
Step 4: Start Compilation
```
make -j$(nproc)
```
Step 5: Install OpenCV
```
sudo make install
```
Step 6: Confirm Installation
Check the OpenCV version using bindings for different programming languages to verify the installation. Let’s use Python.
```
python3 -c "import cv2; print(cv2.__version__)"
```



## Building the Source Code

Step 1: Clone the repository in the `/root` directory and create a build folder
```
git clone https://github.com/satvik-tandon/FDT.git
cd FDT
mkdir -p build && cd build
```
Step 2: Run cmake and compile all the files
```
cmake ..
make
```
Step  3: An executible will be created. Run it.
```
./fdt
```

## All-in-one Installation

I have also attached a script file for running the full project from scratch. You may run it as follows in the `/root`:
```
bash fdt.sh
```
## Classes and Methods Used 

### 1. VideoCapture 
Class for video capturing from video files, image sequences or cameras.The class provides C++ API for capturing video from cameras or for reading video files and image sequences.

### 2. Mat
The class Mat represents an n-dimensional dense numerical single-channel or multi-channel array. It can be used to store real or complex-valued vectors and matrices, grayscale or color images, voxel volumes, vector fields, point clouds, tensors, histograms. The data layout of the array M is defined by the array M.step[], so that the address of element (i0,...,iM.dims−1), where 0≤ik<M.size[k], is computed as:

> **addr(M<sub>i<sub>0</sub>,...,i<sub>M.dims−1</sub></sub>)=M.data+M.step[0]∗i<sub>0</sub>+M.step[1]∗i<sub>1</sub>+...+M.step[M.dims−1]∗<sub>i<sub>M.dims−1</sub></sub>**

In case of a 2-dimensional array, the above formula is reduced to:

> **addr(M<sub>i,j</sub>)=M.data+M.step[0]∗i+M.step[1]∗j**

### 3. FaceDetector 
It is a user-defined class which uses the `cv::dnn::Net` class and load weights from a pre-trained caffe model.The model has a constructor in which we will load the model weights. Additionally it has a method `std::vector<cv::Rect> detect_face_rectangles(const cv::Mat &frame)` that takes an input image and gives a vector of detected faces.In addition to the model, I have also saved:-
+ `input_image_width/height_` dimensions of the input image
+ `scale_factor_` scaling factor when converting the image to a data blob
+ `mean_values_` the mean values for each channel the network was trained with. These values will be subtracted from the image when transforming the image to a data blob.
+ `confidence_threshold_` the confidence threshold to use when detecting faces. The model will supply a confidence value for each detected face. Faces with a confidence value >= **confidence_threshold_** will be kept. All other faces are discarded.

### 4. Net
This class allows to create and manipulate comprehensive artificial neural networks.Neural network is presented as directed acyclic graph (DAG), where vertices are Layer instances, and edges specify relationships between layers inputs and outputs.Each network layer has unique integer id and unique string name inside its network.

### 5. imshow()
`imshow()` method is used to display an image in a window. The window automatically fits the image size.

### 6. waitkey()
`waitkey()` function allows users to display a window for given milliseconds or until any key is pressed. It takes time in milliseconds as a parameter and waits for the given time to destroy the window, if 0 is passed in the argument it waits till any key is pressed.

### 7. destroyAllWindows()
`destroyAllWindows()` function allows users to destroy or close all windows at any time after exiting the script. If you have multiple windows open at the same time and you want to close then you would use this function. It doesn’t take any parameters and doesn’t return anything.

### 8. readNetFromCaffe()
`readNetFromCaffe()` reads a network model stored in Caffe framework's format.













