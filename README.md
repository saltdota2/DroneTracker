# Drone Target Tracker (OpenCV & C++)

A real-time object tracking application built with C++ and OpenCV. This project performs real-time object tracking using OpenCV's CSRT tracker.

It calculates the target deviation from the frame center (`errorX`, `errorY`), producing control signals that can be used in drone PID-based tracking systems.

![Demo](demo.gif)

## Features
* **Real-time Object Tracking:** Utilizes the robust CSRT tracking algorithm from OpenCV.
* **Error Calculation:** Computes the exact X and Y offset of the target relative to the frame center.
* **OOP Architecture:** Clean, modular, and maintainable Object-Oriented design separating video capture logic from tracking algorithms.
* **Interactive Controls:** Select and re-select targets on the fly.

## Project Structure
```text
DroneTracker/
├── src/
│   ├── main.cpp        # Entry point, video capture, and user input
│   ├── tracker.h       # Tracker class declaration
│   └── tracker.cpp     # Tracker class implementation
├── CMakeLists.txt      # Build configuration
└── README.md

## Tech Stack
- C++17
- OpenCV 4.x
- CMake
- Ubuntu Linux

## Prerequisites
To build and run this project, you need the following installed on your system:

C++17 compatible compiler (GCC/Clang)

CMake (>= 3.16)

OpenCV (>= 4.x) with the tracking module

Build Instructions
Clone the repository:

Bash
git clone [https://github.com/saltdota2/DroneTracker.git](https://github.com/saltdota2/DroneTracker.git)
cd DroneTracker
Create a build directory and run CMake:

Bash
mkdir build && cd build
cmake ..
Compile the project:

Bash
make
Usage
Run the executable from the build directory:

Bash
./DroneTracker

## Controls
- **Mouse:** Select target ROI
- **SPACE:** Reinitialize target tracking
- **ESC:** Exit application

## Future Improvements
- Automatic target re-detection after loss
- PID-based drone control integration
- Kalman filtering for smoother tracking
