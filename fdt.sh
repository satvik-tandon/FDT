#!/bin/bash
sudo apt update && sudo apt upgrade -y
sudo apt install gcc g++ make -y

#building and setting up opencv libraries
sudo apt install libopencv-dev python3-opencv -y
sudo apt install build-essential cmake git pkg-config libgtk-3-dev libavcodec-dev libavformat-dev libswscale-dev libv4l-dev libxvidcore-dev libx264-dev libjpeg-dev libpng-dev libtiff-dev gfortran openexr libatlas-base-dev python3-dev python3-numpy libtbb2 libtbb-dev libdc1394-dev libopenexr-dev libgstreamer-plugins-base1.0-dev libgstreamer1.0-dev -y
mkdir opencv_build && cd opencv_build
git clone https://github.com/opencv/opencv.git
git clone https://github.com/opencv/opencv_contrib.git
cd /root/opencv_build/opencv
mkdir -p build && cd build
echo "hello"
cmake -D CMAKE_BUILD_TYPE=RELEASE CMAKE_INSTALL_PREFIX=/usr/local INSTALL_C_EXAMPLES=ON INSTALL_PYTHON_EXAMPLES=ON OPENCV_GENERATE_PKGCONFIG=ON OPENCV_EXTRA_MODULES_PATH=~/opencv_build/opencv_contrib/modules BUILD_EXAMPLES=ON ..
make -j$(nproc)
sudo make install

#setting up face detection tool
git clone https://github.com/satvik-tandon/FDT.git
cd /root/FDT
mkdir -p build && cd build
cmake ..
make

echo"INSTALLATION COMPLETED.NOW RUNNING FACE DETECTION TOOL"
./fdt
