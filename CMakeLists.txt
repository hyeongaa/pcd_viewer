cmake_minimum_required(VERSION 3.5)
project(pcl_vis)

set(CMAKE_CXX_STANDARD 11)

# Find PCL package
find_package(PCL 1.2 REQUIRED)

# Include PCL headers
include_directories(${PCL_INCLUDE_DIRS})

# Link PCL libraries
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})

# Executable
add_executable(pcl_vis main.cpp)

# Link PCL libraries to the executable
target_link_libraries(pcl_vis ${PCL_LIBRARIES})

# Use C++11 threads
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# Use std::this_thread::sleep_for() instead of boost::this_thread::sleep()
target_compile_definitions(pcl_vis PRIVATE USE_STD_THREAD)

