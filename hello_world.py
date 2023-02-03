"""
This is a test file for the sigma python sdk. It is equivalent to the hello_world.cpp example given in the
Haptic SDK Documentation.
"""


import build.sigma_sdk_python as sigma


def main():
    if sigma.dhdOpen() < 0:
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
        sigma.dhdGetPosition(posX, posY, posZ)
        # Compute Spring Model
        fX = -K * posX
        fY = -K * posY
        fZ = -K * posZ
        # Apply force
        sigma.dhdSetForce(fX, fY, fZ)
        # Exit if the button is pushed
        done = sigma.dhdGetButton(0)

    # close the connection
    sigma.dhdClose()


if __name__ == "__main__":
    main()
