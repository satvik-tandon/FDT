**“Computer vision and machine learning have really started to take off, but for most people, the whole idea of what a computer is seeing when it’s looking at an image is relatively obscure.” – Mike Kreiger**

In this project I have built a model which detects the face in video from webcam in realtime. I have built the project on C++ and opencv4. The versions used for CMake and openCV are 3.25.0 and 4.2.0 respectively. Using a pre-trained caffe model, it detects your face and draw a rectangle around it to indicate the face.



**Installing OpenCV**

I have used parts of OpenCV and its OpenCV_contrib module. The most convenient way is by building OpenCV from source. I have used OpenCV version 4.2.0 on Ubuntu 22.04.

Step 1. Install OpenCV Dependencies and Build Tools
```linux
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



**Building the Source Code**

Step 1: Clone the repository in the */root* directory and create a build folder
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



I have also attached a script file for running the full project from scratch. You may run it as follows in the */root*:
```
bash fdt.sh
```

**THANKS FOR READING. :)**
