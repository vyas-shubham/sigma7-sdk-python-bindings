cmake_minimum_required(VERSION 3.14)
set(CMAKE_CXX_STANDARD 11)


project(Sigma7HelloWorld)

set(sigmaSDKDir ${CMAKE_CURRENT_SOURCE_DIR}/../sigmaSDK)

find_library (force_dimension_sdk_LIBRARY_DHD REQUIRED
                NAMES dhd
                PATHS ${sigmaSDKDir}/lib/release/lin-x86_64-gcc/)
find_library (force_dimension_sdk_LIBRARY_DRD REQUIRED
                NAMES drd
                PATHS ${sigmaSDKDir}/lib/release/lin-x86_64-gcc/)

find_package(Eigen3 REQUIRED)


message(STATUS "force_dimension_sdk_LIBRARY_DHD: ${force_dimension_sdk_LIBRARY_DHD}")
message(STATUS "force_dimension_sdk_LIBRARY_DRD: ${force_dimension_sdk_LIBRARY_DRD}")

link_directories(${sigmaSDKDir}/lib/release/lin-x86_64-gcc/)
include_directories(${sigmaSDKDir}/include/ ${EIGEN3_INCLUDE_DIR})


add_executable(HelloWorld hello_world.cpp)
target_link_libraries(HelloWorld dhd drd pthread usb-1.0 rt dl)