cmake_minimum_required(VERSION 3.16)

project(DroneTracker)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
SET(CMAKE_CXX_EXTENSIONS OFF)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(DroneTracker src/main.cpp src/tracker.cpp)
target_link_libraries(DroneTracker ${OpenCV_LIBS})
