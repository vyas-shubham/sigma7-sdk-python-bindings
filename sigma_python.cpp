// Create bindings for sigma standard SDK based on the header files

#include <pybind11/pybind11.h>
// C++ library headers
#include <iomanip>
#include <iostream>

// project headers
#include "dhdc.h"

namespace py = pybind11;

PYBIND11_MODULE(sigma_sdk_python, sigmaSDK) {
  sigmaSDK.doc() = "pybind11 SigmaSDK plugin";  // optional module docstring
  // Initial test functions from test example
  sigmaSDK.def("dhdOpen", &dhdOpen,
               "This function opens a connection to the first available device "
               "connected to the system. The order in which devices are opened "
               "persists until devices are added or removed.");

  sigmaSDK.def("dhdGetPosition", &dhdGetPosition,
               "This function retrieves the position of the end-effector in "
               "Cartesian coordinates. Please refer to your device user manual "
               "for more information on your device coordinate system.");

  sigmaSDK.def("dhdSetForce", &dhdSetForce,
               "This function sets the desired force vector in Cartesian "
               "coordinates to be applied to the end-effector of the device.");

  sigmaSDK.def("dhdGetButton", &dhdGetButton,
               "This function returns the status of the button located on the "
               "end-effector.");

  sigmaSDK.def("dhdClose", &dhdClose,
               "This function closes the connection to a particular device.");

  // Create enum for dhd_errors
  py::enum_<dhd_errors>(sigmaSDK, "dhd_errors")
      .value("DHD_NO_ERROR", DHD_NO_ERROR)
      .value("DHD_ERROR", DHD_ERROR)
      .value("DHD_ERROR_COM", DHD_ERROR_COM)
      .value("DHD_ERROR_DHC_BUSY", DHD_ERROR_DHC_BUSY)
      .value("DHD_ERROR_NO_DRIVER_FOUND", DHD_ERROR_NO_DRIVER_FOUND)
      .value("DHD_ERROR_NO_DEVICE_FOUND", DHD_ERROR_NO_DEVICE_FOUND)
      .value("DHD_ERROR_NOT_AVAILABLE", DHD_ERROR_NOT_AVAILABLE)
      .value("DHD_ERROR_TIMEOUT", DHD_ERROR_TIMEOUT)
      .value("DHD_ERROR_GEOMETRY", DHD_ERROR_GEOMETRY)
      .value("DHD_ERROR_EXPERT_MODE_DISABLED", DHD_ERROR_EXPERT_MODE_DISABLED)
      .value("DHD_ERROR_NOT_IMPLEMENTED", DHD_ERROR_NOT_IMPLEMENTED)
      .value("DHD_ERROR_OUT_OF_MEMORY", DHD_ERROR_OUT_OF_MEMORY)
      .value("DHD_ERROR_DEVICE_NOT_READY", DHD_ERROR_DEVICE_NOT_READY)
      .value("DHD_ERROR_FILE_NOT_FOUND", DHD_ERROR_FILE_NOT_FOUND)
      .value("DHD_ERROR_CONFIGURATION", DHD_ERROR_CONFIGURATION)
      .value("DHD_ERROR_INVALID_INDEX", DHD_ERROR_INVALID_INDEX)
      .value("DHD_ERROR_DEPRECATED", DHD_ERROR_DEPRECATED)
      .value("DHD_ERROR_NULL_ARGUMENT", DHD_ERROR_NULL_ARGUMENT)
      .value("DHD_ERROR_REDUNDANT_FAIL", DHD_ERROR_REDUNDANT_FAIL)
      .value("DHD_ERROR_NOT_ENABLED", DHD_ERROR_NOT_ENABLED)
      .value("DHD_ERROR_DEVICE_IN_USE", DHD_ERROR_DEVICE_IN_USE)
      .value("DHD_ERROR_INVALID", DHD_ERROR_INVALID)
      .value("DHD_ERROR_NO_REGULATION", DHD_ERROR_NO_REGULATION)
      .export_values();

  // Error reporting functions
  sigmaSDK.def("dhdErrorGetLast", &dhdErrorGetLast,
               "Returns the last error code encountered in the running thread. "
               "See error management for details.");

  sigmaSDK.def("dhdErrorGetLastStr", &dhdErrorGetLastStr,
               "GReturns a brief string describing the last error encountered "
               "in the running thread. See error management for details.");

  sigmaSDK.def("dhdErrorGetStr", &dhdErrorGetStr,
               "Returns a brief string describing a given error code. See "
               "error management for details.");

  // More functions added as used
  // Template Function for new bindings
  // sigmaSDK.def("name", &name, "SDK documentation string");
  sigmaSDK.def("dhdEnableSimulator", &dhdEnableSimulator,
               "This function enables the device simulator support. This "
               "enables network access on the loopback interface.");

  sigmaSDK.def("dhdGetDeviceCount", &dhdGetDeviceCount,
               "This function returns the number of compatible Force Dimension "
               "devices connected to the system. This encompasses all devices "
               "connected locally, including devices already locked by other "
               "applications. Devices are given a unique identifier, as "
               "explained in the multiple devices section.");

  sigmaSDK.def("dhdGetAvailableCount", &dhdGetAvailableCount,
               "This function returns the number of available Force Dimension "
               "devices connected to the system. This encompasses all devices "
               "connected locally, but excludes devices already locked by "
               "other applications. Devices are given a unique identifier, as "
               "explained in the multiple devices section.");

  sigmaSDK.def("dhdSetDevice", &dhdSetDevice,
               "This function selects the default device that will receive the "
               "SDK commands. The SDK supports multiple devices. This routine "
               "allows the programmer to decide which device the SDK "
               "dhd_single_device_call single-device calls will address. Any "
               "subsequent SDK call that does not specifically mention the "
               "device ID in its parameter list will be sent to that device.");

  sigmaSDK.def("dhdGetDeviceID", &dhdGetDeviceID,
               "This function returns the ID of the current default device.");

  sigmaSDK.def("dhdGetSerialNumber", &dhdGetSerialNumber,
               "This function returns the device serial number.");

  sigmaSDK.def("dhdOpenType", &dhdOpenType,
               "This function opens a connection to the first device of a "
               "given type connected to the system. The order in which devices "
               "are opened persists until devices are added or removed.");

  sigmaSDK.def("dhdOpenSerial", &dhdOpenSerial,
               "This function opens a connection to the device with a given "
               "serial number (available on recent models only).");

  sigmaSDK.def(
      "dhdOpenID", &dhdOpenID,
      "This function opens a connection to one particular device connected to "
      "the system. The order in which devices are opened persists until "
      "devices are added or removed. If the device at the specified index is "
      "already opened, its device ID is returned.");

  sigmaSDK.def(
      "dhdCheckControllerMemory", &dhdCheckControllerMemory,
      "This function evaluates the integrity of the device controller firmware "
      "and internal configuration on supported device types.");

  sigmaSDK.def(
      "dhdStop", &dhdStop,
      "This function stops all forces on the device. This routine disables the "
      "force on the haptic device and puts it into BRAKE mode.");

  sigmaSDK.def(
      "dhdGetComMode", &dhdGetComMode,
      "This function retrieves the COM operation mode on compatible devices.");

  sigmaSDK.def(
      "dhdEnableForce", &dhdEnableForce,
      "This function enables the force mode in the device controller.");

  sigmaSDK.def("dhdEnableGripperForce", &dhdEnableGripperForce,
               "This function enables the gripper force mode in the device "
               "controller. This function is only relevant to devices that "
               "have a gripper with a default closed or opened state. It does "
               "not apply to the sigma.x and omega.x range of devices, whose "
               "gripper does not have a default state. For those devices, the "
               "gripper force is enabled/disabled by dhdEnableForce().");

  sigmaSDK.def("dhdGetSystemType", &dhdGetSystemType,
               "This function returns the haptic device type. As this SDK can "
               "be used to control all of Force Dimension haptic products, "
               "this can help programmers ensure that their application is "
               "running on the appropriate target haptic device.");

  sigmaSDK.def(
      "dhdGetSystemRev", &dhdGetSystemRev,
      "This function returns the revision associated with this instance of "
      "haptic device type. As this SDK can be used to control all of Force "
      "Dimension haptic products, this can help programmers ensure that their "
      "application is running on the appropriate target haptic device.");

  sigmaSDK.def("dhdGetSystemName", &dhdGetSystemName,
               "This function returns the haptic device type. As this SDK can "
               "be used to control all of Force Dimension haptic products, "
               "this can help programmers ensure that their application is "
               "running on the appropriate target haptic device.");

  sigmaSDK.def(
      "dhdGetVersion", &dhdGetVersion,
      "This function returns the device controller version. As this SDK can be "
      "used to control all of Force Dimension haptic products, this can help "
      "programmers ensure that their application is running on the appropriate "
      "version of the haptic controller.");

  sigmaSDK.def(
      "dhdGetVersionStr", &dhdGetVersionStr,
      "This function returns the device controller version string. As this SDK "
      "can be used to control all of Force Dimension haptic products, this can "
      "help programmers ensure that their application is running on the "
      "appropriate version of the haptic controller.");

  sigmaSDK.def(
      "dhdGetSDKVersion", &dhdGetSDKVersion,
      "This function returns the SDK complete set of version numbers.");

  sigmaSDK.def(
      "dhdGetSDKVersionStr", &dhdGetSDKVersionStr,
      "This function returns a string that fully describes the SDK version.");

  sigmaSDK.def("dhdGetComponentVersionStr", &dhdGetComponentVersionStr,
               "This function returns a string that describes an internal "
               "component version (if present).");

  sigmaSDK.def("dhdGetStatus", &dhdGetStatus,
               "This function returns the status vector of the haptic device. "
               "The status is described in the status section.");

  sigmaSDK.def(
      "dhdGetDeviceAngleRad", &dhdGetDeviceAngleRad,
      "This function retrieves the device base plate angle around the Y axis.");

  sigmaSDK.def(
      "dhdGetDeviceAngleDeg", &dhdGetDeviceAngleDeg,
      "This function retrieves the device base plate angle around the Y axis.");

  sigmaSDK.def("dhdGetEffectorMass", &dhdGetEffectorMass,
               "This function retrieves the mass of the end-effector currently "
               "defined for a device. The gripper mass is used in the gravity "
               "compensation feature.");

  sigmaSDK.def("dhdGetSystemCounter", &dhdGetSystemCounter,
               "This function returns a timestamp computed from the "
               "high-resolution system counter, expressed in microseconds. "
               "This function is deprecated, please use dhdGetTime() instead.");

  sigmaSDK.def("dhdGetButton", &dhdGetButton,
               "This function returns the status of the button located on the "
               "end-effector.");

  sigmaSDK.def(
      "dhdGetButtonMask", &dhdGetButtonMask,
      "This function returns the 32-bit binary mask of the device buttons.");

  sigmaSDK.def("dhdSetOutput", &dhdSetOutput,
               "This function sets the user programmable output bits on "
               "devices that support it.");

  sigmaSDK.def("dhdIsLeftHanded", &dhdIsLeftHanded,
               "This function returns true if the device is configured for "
               "left-handed use, false otherwise.");

  sigmaSDK.def(
      "dhdHasBase", &dhdHasBase,
      "This function returns true if the device has a base, false otherwise.");

  sigmaSDK.def(
      "dhdHasWrist", &dhdHasWrist,
      "This function returns true if the device has a wrist, false otherwise.");

  sigmaSDK.def("dhdHasActiveWrist", &dhdHasActiveWrist,
               "This function returns true if the device has an active wrist, "
               "false otherwise.");

  sigmaSDK.def("dhdHasGripper", &dhdHasGripper,
               "This function returns true if the device has a gripper, false "
               "otherwise.");

  sigmaSDK.def("dhdHasActiveGripper", &dhdHasActiveGripper,
               "This function returns true if the device has an active "
               "gripper, false otherwise.");

  sigmaSDK.def("dhdReset", &dhdReset,
               "This function puts the device in RESET mode.");

  sigmaSDK.def(
      "dhdResetWrist", &dhdResetWrist,
      "This function resets the wrist calibration on a delta.6 haptic device.");

  sigmaSDK.def(
      "dhdWaitForReset", &dhdWaitForReset,
      "This function puts the device in RESET mode and wait for the user to "
      "calibrate the device. Optionally, a timeout can be defined after which "
      "the call returns even if calibration has not occurred.");

  sigmaSDK.def(
      "dhdSetStandardGravity", &dhdSetStandardGravity,
      "This function sets the standard gravity constant used in gravity "
      "compensation. By default, the constant is set to 9.81 m/s^2.");

  sigmaSDK.def(
      "dhdSetGravityCompensation", &dhdSetGravityCompensation,
      "This function toggles the use of the gravity compensation feature.");

  sigmaSDK.def(
      "dhdSetBrakes", &dhdSetBrakes,
      "This function toggles the device electromagnetic brakes state.");

  sigmaSDK.def(
      "dhdSetDeviceAngleRad", &dhdSetDeviceAngleRad,
      "This function sets the device base plate angle around the (inverted) Y "
      "axis. Please refer to your device user manual for more information on "
      "your device coordinate system. An angle value of 0 corresponds to the "
      "device upright "
      "position, with its base plate perpendicular to axis X. An angle value "
      "of Pi/2 corresponds to the device base plate resting horizontally.");

  sigmaSDK.def(
      "dhdSetDeviceAngleDeg", &dhdSetDeviceAngleDeg,
      "This function sets the device base plate angle around the (inverted) Y "
      "axis. Please refer to your device user manual for more information on "
      "your device coordinate system. An angle value of 0 corresponds to the "
      "device upright "
      "position, with its base plate perpendicular to axis X. An angle value "
      "of 90 corresponds to the device base plate resting horizontally.");

  sigmaSDK.def("dhdSetEffectorMass", &dhdSetEffectorMass,
               "This function defines the mass of the end-effector. This "
               "function is required to provide accurate gravity compensation "
               "when custom-made or modified end-effectors are used.");

  sigmaSDK.def("dhdGetPosition", &dhdGetPosition,
               "This function retrieves the position of the end-effector in "
               "Cartesian coordinates. Please refer to your device user manual "
               "for more information on your device coordinate system.");

  sigmaSDK.def(
      "dhdGetForce", &dhdGetForce,
      "This function retrieves the force vector applied to the end-effector.");

  sigmaSDK.def("dhdSetForce", &dhdSetForce,
               "This function sets the desired force vector in Cartesian "
               "coordinates to be applied to the end-effector of the device.");

  sigmaSDK.def("dhdGetOrientationRad", &dhdGetOrientationRad,
               "For devices with a wrist structure, this function retrieves "
               "individual angle of each joint, starting with the one located "
               "nearest to the wrist base plate. For the DHD_DEVICE_OMEGA33 "
               "and DHD_DEVICE_OMEGA33_LEFT devices, angles are computed with "
               "respect to their internal reference frame, which is rotated 45 "
               "degrees around the Y axis. Please refer to your device user "
               "manual for more information on your device coordinate system.");

  sigmaSDK.def("dhdGetOrientationDeg", &dhdGetOrientationDeg,
               "For devices with a wrist structure, This function retrieves "
               "individual angle of each joint, starting with the one located "
               "nearest to the wrist base plate. For the DHD_DEVICE_OMEGA33 "
               "and DHD_DEVICE_OMEGA33_LEFT devices, angles are computed with "
               "respect to their internal reference frame, which is rotated 45 "
               "degrees around the Y axis. Please refer to your device user "
               "manual for more information on your device coordinate system.");

  sigmaSDK.def(
      "dhdGetPositionAndOrientationRad", &dhdGetPositionAndOrientationRad,
      "This function retrieves the position and orientation of the "
      "end-effector in Cartesian coordinates. For devices with a wrist "
      "structure, the orientation is expressed as the individual angle of each "
      "joint, starting with the one located nearest to the wrist base plate. "
      "For the DHD_DEVICE_OMEGA33 and DHD_DEVICE_OMEGA33_LEFT devices, angles "
      "are computed with respect to their internal reference frame, which is "
      "rotated 45 degrees around the Y axis. Please refer to your device user "
      "manual for more information on your device coordinate system.");

  sigmaSDK.def(
      "dhdGetPositionAndOrientationDeg", &dhdGetPositionAndOrientationDeg,
      "This function retrieves the position and orientation of the "
      "end-effector in Cartesian coordinates. For devices with a wrist "
      "structure, the orientation is expressed as the individual angle of"
      "each joint, starting with the one located nearest to the wrist base"
      "plate. For the DHD_DEVICE_OMEGA33 and DHD_DEVICE_OMEGA33_LEFT"
      "devices, angles are computed with respect to their internal"
      "reference frame, which is rotated 45 degrees around the Y axis."
      "Please refer to your device user manual for more information on your"
      "device coordinate system.");

  // Error During Binding Generation
  // sigmaSDK.def(
  //     "dhdGetPositionAndOrientationFrame",
  //     &dhdGetPositionAndOrientationFrame, "This function retrieves the "
  //     "position and orientation matrix of the end-effector in Cartesian"
  //     "coordinates. Please refer to your device user manual for more"
  //     "information on your device coordinate system.");

  sigmaSDK.def("dhdGetForceAndTorque", &dhdGetForceAndTorque,
               "This function retrieves the force and torque vectors applied"
               " to the device end-effector.");

  sigmaSDK.def("dhdSetForceAndTorque", &dhdSetForceAndTorque,
               "This function sets the desired force and torque vectors to be"
               " applied to the device end-effector.");

  // Error During Binding Generation
  // sigmaSDK.def("dhdGetOrientationFrame", &dhdGetOrientationFrame,
  //              "This function retrieves the rotation matrix of the wrist "
  //              "structure. The identity matrix is returned for devices that "
  //              "do not support orientations.");

  sigmaSDK.def("dhdGetGripperAngleDeg", &dhdGetGripperAngleDeg,
               "This function retrieves the gripper opening angle in "
               "degrees.");

  sigmaSDK.def("dhdGetGripperAngleRad", &dhdGetGripperAngleRad,
               "This function retrieves the gripper opening angle in "
               "radians.");

  sigmaSDK.def(
      "dhdGetGripperGap", &dhdGetGripperGap,
      "This function retrieves the gripper opening distance in meters.");

  sigmaSDK.def(
      "dhdGetGripperThumbPos", &dhdGetGripperThumbPos,
      "This function retrieves the position in Cartesian coordinates of "
      "thumb rest location of the force gripper structure if present.");

  sigmaSDK.def(
      "dhdGetGripperFingerPos", &dhdGetGripperFingerPos,
      "This function retrieves the position in Cartesian coordinates of "
      "forefinger rest location of the force gripper structure if present.");

  sigmaSDK.def(
      "dhdGetComFreq", &dhdGetComFreq,
      "This function returns the communication refresh rate between the "
      "computer and the device. Refresh rate computation is based on function"
      " calls that apply a force on the device (e.g. dhdSetForce()).");

  sigmaSDK.def("dhdSetForceAndGripperForce", &dhdSetForceAndGripperForce,
               "This function sets the desired force vector in Cartesian "
               "coordinates and the desired grasping force to be applied to "
               "the device end-effector and force gripper.");

  sigmaSDK.def("dhdSetForceAndTorqueAndGripperForce",
               &dhdSetForceAndTorqueAndGripperForce,
               "This function sets the desired force and torque vectors in "
               "Cartesian coordinates and the desired grasping force to be "
               "applied to the device end-effector and force gripper.");

  sigmaSDK.def(
      "dhdGetForceAndTorqueAndGripperForce",
      &dhdGetForceAndTorqueAndGripperForce,
      "This function retrieves the force and torque vectors applied to the "
      "device end-effector, as well as the force applied to the gripper.");

  sigmaSDK.def("dhdConfigLinearVelocity", &dhdConfigLinearVelocity,
               "This function configures the internal velocity computation "
               "estimator. This only applies to the device base.");

  sigmaSDK.def(
      "dhdGetLinearVelocity", &dhdGetLinearVelocity,
      "This function retrieves the estimated instantaneous translational "
      "velocity. See velocity estimator for details.");

  sigmaSDK.def("dhdConfigAngularVelocity", &dhdConfigAngularVelocity,
               "This function configures the internal velocity computation "
               "estimator. This only applies to the device wrist.");

  sigmaSDK.def(
      "dhdGetAngularVelocityRad", &dhdGetAngularVelocityRad,
      "This function retrieves the estimated instantaneous angular velocity"
      "in rad/s. See velocity estimator for details.");

  sigmaSDK.def(
      "dhdGetAngularVelocityDeg", &dhdGetAngularVelocityDeg,
      "This function retrieves the estimated instantaneous angular velocity "
      "in deg/s. See velocity estimator for details.");

  sigmaSDK.def("dhdConfigGripperVelocity", &dhdConfigGripperVelocity,
               "This function configures the internal velocity computation "
               "estimator. This only applies to the device gripper.");

  sigmaSDK.def(
      "dhdGetGripperLinearVelocity", &dhdGetGripperLinearVelocity,
      "This function retrieves the estimated instantaneous linear velocity "
      "of the gripper in m/s. See velocity estimator for details.");

  sigmaSDK.def(
      "dhdGetGripperAngularVelocityRad", &dhdGetGripperAngularVelocityRad,
      "This function retrieves the estimated instantaneous angular velocity "
      "of the gripper in rad/s. Velocity computation can be configured by "
      "calling dhdConfigGripperVelocity. By default DHD_VELOCITY_WINDOW "
      "and DHD_VELOCITY_WINDOWING are used. See velocity estimator for "
      "details.");

  sigmaSDK.def(
      "dhdGetGripperAngularVelocityDeg", &dhdGetGripperAngularVelocityDeg,
      "This function retrieves the estimated instantaneous angular velocity "
      "of the gripper in deg/s. Velocity computation can be configured by "
      "calling dhdConfigGripperVelocity. By default DHD_VELOCITY_WINDOW "
      "and DHD_VELOCITY_WINDOWING are used. See velocity estimator for "
      "details.");

  sigmaSDK.def("dhdEmulateButton", &dhdEmulateButton,
               "This function enables the button behavior emulation in "
               "devices that feature a gripper.");

  sigmaSDK.def(
      "dhdGetBaseAngleXRad", &dhdGetBaseAngleXRad,
      "This function retrieves the device base plate angle around the X "
      "axis.");

  sigmaSDK.def(
      "dhdGetBaseAngleXDeg", &dhdGetBaseAngleXDeg,
      "This function retrieves the device base plate angle around the X "
      "axis.");

  sigmaSDK.def("dhdSetBaseAngleXRad", &dhdSetBaseAngleXRad,
               "This function sets the device base plate angle around the X "
               "axis. Please refer to your device user manual for more "
               "information on your device coordinate system.");

  sigmaSDK.def("dhdSetBaseAngleXDeg", &dhdSetBaseAngleXDeg,
               "This function sets the device base plate angle around the X "
               "axis. Please refer to your device user manual for more "
               "information on your device coordinate system.");

  sigmaSDK.def("dhdGetBaseAngleZRad", &dhdGetBaseAngleZRad,
               "This function retrieves the device base plate angle around "
               "the vertical Z axis.");

  sigmaSDK.def("dhdGetBaseAngleZDeg", &dhdGetBaseAngleZDeg,
               "This function retrieves the device base plate angle around "
               "the vertical Z axis.");

  sigmaSDK.def("dhdSetBaseAngleZRad", &dhdSetBaseAngleZRad,
               "This function sets the device base plate angle around the "
               "vertical Z axis. Please refer to your device user manual for "
               "more information on your device coordinate system.");

  sigmaSDK.def("dhdSetBaseAngleZDeg", &dhdSetBaseAngleZDeg,
               "This function sets the device base plate angle around the "
               "vertical Z axis. Please refer to your device user manual for "
               "more information on your device coordinate system.");

  sigmaSDK.def("dhdSetVibration", &dhdSetVibration,
               "This function applies a vibration to the end-effector. The "
               "vibration is added to the force requested by dhdSetForce "
               "and the like. The vibration application mechanism depends "
               "on the specific device type, and is currently only "
               "available on devices with dedicated vibration actuators.");

  sigmaSDK.def(
      "dhdSetMaxForce", &dhdSetMaxForce,
      "This function defines a limit (in N) to the force magnitude that can "
      "be applied by the haptic device. The f N limit applies to all "
      "dhdSetForce and related calls, and ensures that the force applied to "
      "the device end-effector remains below the requested value. If the f "
      "argument is negative, the limit is disabled and the full range of "
      "force available can be applied.");

  sigmaSDK.def(
      "dhdSetMaxTorque", &dhdSetMaxTorque,
      "This function defines a limit (in Nm) to the torque magnitude that can "
      "be applied by the haptic device. The t Nm limit applies to all "
      "dhdSetForceAndTorque() and related calls, and ensures that the torque "
      "applied to the device end-effector remains below the requested "
      "value. If the t argument is negative, the limit is disabled and the "
      "full range of torque available can be applied.");

  sigmaSDK.def(
      "dhdSetMaxGripperForce", &dhdSetMaxGripperForce,
      "This function defines a limit (in N) to the force magnitude that can "
      "be applied by the haptic device gripper. The f N limit applies to "
      "dhdSetForceAndTorqueAndGripperForce and related calls, and ensures "
      "that the force applied to the device gripper remains below the "
      "requested value. If the f argument is negative, the limit is disabled"
      " and the full range of gripper force available can be applied.");

  sigmaSDK.def("dhdGetMaxForce", &dhdGetMaxForce,
               "This function retrieves the current limit (in N) to the force "
               "magnitude that can be applied by the haptic device. If the "
               "return value is negative, the limit is disabled and the "
               "full range of force available can be applied.");

  sigmaSDK.def("dhdGetMaxTorque", &dhdGetMaxTorque,
               "This function retrieves the current limit (in Nm) to the "
               "torque magnitude that can be applied by the haptic device. If"
               " the return value is negative, the limit is disabled and the"
               " full range of torque available can be applied.");

  sigmaSDK.def("dhdGetMaxGripperForce", &dhdGetMaxGripperForce,
               "This function retrieves the current limit (in N) to the force"
               " magnitude that can be applied by the haptic device gripper."
               "If the return value is negative, the limit is disabled and"
               "the full range of gripper force available can be applied.");
}
