"""
This example implements a simple gravity compensation loop for a single
haptic device. It is equivalent to the single_device.cpp example given in the
Haptic SDK Documentation.
"""

import build.sigma_sdk_python as sigma

def main():
    # Get device count
    if sigma.dhdGetDeviceCount() <= 0:
        errorStr = sigma.dhdErrorGetLastStr()
        print("Error: {}".format(errorStr))
        return

    # Open the first available device
    if sigma.dhdOpen() < 0:
        errorStr = sigma.dhdErrorGetLastStr()
        print("Error: {}".format(errorStr))
        return

    # Haptic loop
    while True:
        # Apply a null force to put the device in gravity compensation
        if sigma.dhdSetForce(0.0, 0.0, 0.0) < 0:
            errorStr = sigma.dhdErrorGetLastStr()
            print("Error: {}".format(errorStr))
            break
        # Exit the haptic loop on button press
        if sigma.dhdGetButton(0):
            break

if __name__ == "__main__":
    main()