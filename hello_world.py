"""
This is a test file for the sigma python sdk. It is equivalent to the hello_world.cpp example given in the
Haptic SDK Documentation.
"""

import sys
import build.sigma_sdk_python as sigma


def main(deviceID="1"):
    if sigma.dhdOpenID(deviceID) < 0:
        print("Error: cannot open device")
        return

    #  run haptic loop
    done = 0
    K = 1000.0
    posX = 0.0
    posY = 0.0
    posZ = 0.0
    while not done:
        # Get end-effector position
        sigma.dhdGetPosition(posX, posY, posZ, deviceID)
        # Compute Spring Model
        fX = -K * posX
        fY = -K * posY
        fZ = -K * posZ
        # Apply force
        sigma.dhdSetForce(fX, fY, fZ, deviceID)
        # Exit if the button is pushed
        done = sigma.dhdGetButton(0, deviceID)

    # close the connection
    sigma.dhdClose(deviceID)


if __name__ == "__main__":
    if len(sys.argv) < 2:
        sys.exit("Please pass the device ID as the argument to this script. For example, python3 single_device.py 1")
    elif len(sys.argv) > 2:
        sys.exit("Too many arguments! Only one needed for the device ID.")
    else:
        deviceID = str(sys.argv[1])
    main(deviceID)
