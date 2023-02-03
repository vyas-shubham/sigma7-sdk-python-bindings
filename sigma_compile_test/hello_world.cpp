////////////////////////////////////////////////////////////////////////////////
//
//  This example implements a simple spring model which pulls the device
//  towards the center of the workspace. If the user presses the user button,
//  the application exits.
//
////////////////////////////////////////////////////////////////////////////////


// C++ library headers
#include <iostream>
#include <iomanip>

// project headers
#include "dhdc.h"

// constants
constexpr double K = 1000.0;

////////////////////////////////////////////////////////////////////////////////

int main(int argc,
         char* argv[])
{
    // open a connection to the device
    if (dhdOpen() < 0)
    {
        std::cout << "error: cannot open device" << std::endl;
        return -1;
    }

    // run haptic loop
    int done = 0;
    while (!done)
    {
        // get end-effector position
        double px, py, pz;
        dhdGetPosition(&px, &py, &pz);

        // compute spring model
        double fx, fy, fz;
        fx = -K * px;
        fy = -K * py;
        fz = -K * pz;

        // apply forces
        dhdSetForce(fx, fy, fz);

        // exit if the button is pushed
        done += dhdGetButton(0);
    }

    // close the connection
    dhdClose();

    return 0;
}