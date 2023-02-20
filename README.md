# sigma7 SDK Python Bindings

This repo provides Python bindings for the Force Dimension SDK which is used to communicate with sigma.7. The bindings are generated using `pybind11`. As I do not have the sigma.7, I have not been able to test the bindings on real hardware. **Proceed with your own risk and caution when you test on the hardware.**

The bindings for only the `Standard SDK` from the Haptics SDK are provided here. The `Expert SDK` bindings are not yet provided.

## Prerequisites

The following are required to build the bindings:

- Force Dimension SDK: Can be downloaded from their website: <https://www.forcedimension.com/software/sdk>. For ease of use, extract the SDk to the `sigmaSDK` folder in the root of this repo.
- pybind11: Can be installed using `pip install pybind11`
- Build tools such as `cmake` and `make`, and a C++ compiler.

## Build

This has been tested on Ubuntu 22.04.

### Testing the SDK Location and Linking against the SDK

The `sigma_compile_test` folder is a simple test program to verify the correct location of the SDK. It uses the `hello_world.cpp` example from the Haptic SDK Documentation.

- Change the variable `sigmaSDKDir` in the `sigma_compile_test/CMakeLists.txt` file to the location of the SDK.
- Run the following commands inside the `sigma_compile_test` folder:

  ```bash
  mkdir build
  cd build
  cmake ..
  make
  ```

- If everything is correct, the program should compile without any errors.

### Building the Python Bindings

If the test program compiles without any errors, you can proceed to build the Python bindings:

- Change the varibales `sigmaSDKDir` and `pybin11Path` in the `CMakeLists.txt` file to the location of the SDK and location of pybind11 respectively.
- Run the following commands inside the root folder:

  ```bash
  mkdir build
  cd build
  cmake ..
  make
  ```

- If everything is correct, the bindings should compile without any errors.

## Testing/Using the Bindings

The bindings will be compiled to the `build/` folder by default. Two example scripts from the Haptic SDK documentation are translated to Python and are available to test the bindings. The scripts are:

- `hello_world.py`
- `single_device.py`

## Known Issues/Bugs

As I've not yet been able to properly pass the `char` function arguments in the binding, the `DeviceID` argument must be a non-negative integer between `0` and `9`. This is in contrast to the C++ examples in the SDK/header files where the `DeviceID` is a `char` and the default value is `-1`. Pybind11 sees `-1` and double digit integers as a multi-character string instead of a character.
