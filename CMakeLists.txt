cmake_minimum_required(VERSION 3.14)
set(CMAKE_CXX_STANDARD 11)

project(SigmaPythonBindings)

# Path to the Force Dimension SDK directory. Download from
# https://www.forcedimension.com/software/sdk
set(sigmaSDKDir ${CMAKE_CURRENT_SOURCE_DIR}/sigmaSDK)
# Assumed Pybind11 is installed using pip on Python 3.10 pip install pybind11.
# If installed in a different location, specify the path here
set(pybin11Path
    ~/.local/lib/python3.10/site-packages/pybind11/share/cmake/pybind11)

find_library(
  force_dimension_sdk_LIBRARY_DHD REQUIRED
  NAMES dhd
  PATHS ${sigmaSDKDir}/lib/release/lin-x86_64-gcc/)
find_library(
  force_dimension_sdk_LIBRARY_DRD REQUIRED
  NAMES drd
  PATHS ${sigmaSDKDir}/lib/release/lin-x86_64-gcc/)

find_package(Eigen3 REQUIRED)
find_package(pybind11 REQUIRED PATHS ${pybin11Path} NO_DEFAULT_PATH)

message(
  STATUS "force_dimension_sdk_LIBRARY_DHD: ${force_dimension_sdk_LIBRARY_DHD}")
message(
  STATUS "force_dimension_sdk_LIBRARY_DRD: ${force_dimension_sdk_LIBRARY_DRD}")
message(STATUS "EIGEN3_INCLUDE_DIR: ${EIGEN3_INCLUDE_DIR}")
message(STATUS "pybind11_INCLUDE_DIR: ${pybind11_DIR}")

link_directories(${sigmaSDKDir}/lib/release/lin-x86_64-gcc/)
include_directories(${sigmaSDKDir}/include/ ${EIGEN3_INCLUDE_DIR})

pybind11_add_module(sigma_sdk_python sigma_python.cpp)

target_link_libraries(sigma_sdk_python PRIVATE dhd drd pthread usb-1.0 rt dl)
