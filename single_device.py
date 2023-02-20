"""
This example implements a simple gravity compensation loop for a single
haptic device. It is equivalent to the single_device.cpp example given in the
Haptic SDK Documentation.
"""
import sys
import build.sigma_sdk_python as sigma

def main(deviceID="1"):
    # Get device count
    if sigma.dhdGetDeviceCount() <= 0:
        errorStr = sigma.dhdErrorGetLastStr()
        print("Error: {}".format(errorStr))
        return

    # Open the first available device
    if sigma.dhdOpenID(deviceID) < 0:
        errorStr = sigma.dhdErrorGetLastStr()
        print("Error: {}".format(errorStr))
        return

    # Haptic loop
    while True:
        # Apply a null force to put the device in gravity compensation
        if sigma.dhdSetForce(0.0, 0.0, 0.0, deviceID) < 0:
            errorStr = sigma.dhdErrorGetLastStr()
            print("Error: {}".format(errorStr))
            break
        # Exit the haptic loop on button press
        if sigma.dhdGetButton(0, deviceID):
            break

if __name__ == "__main__":
    if len(sys.argv) < 2:
        sys.exit("Please pass the device ID as the argument to this script. For example, python3 single_device.py 1")
    elif len(sys.argv) > 2:
        sys.exit("Too many arguments! Only one needed for the device ID.")
    else:
        deviceID = str(sys.argv[1])
    main(deviceID)