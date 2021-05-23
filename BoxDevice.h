#ifndef D29CD5B9_1CEA_4E6D_8441_E51E26206AC1
#define D29CD5B9_1CEA_4E6D_8441_E51E26206AC1

#include <Arduino.h>
#include "DigitalPin.h"

class BoxDevice {
    DigitalOutputPin pinDriveBack = DigitalOutputPin(9);
    DigitalOutputPin pinDriveForward = DigitalOutputPin(10);
    DigitalInputPin pinArmLowered = DigitalInputPin(11);
    DigitalInputPin pinSwitch = DigitalInputPin(12);

public:
    void moveArmUp() {
        pinDriveBack.setLow();
        pinDriveForward.setHigh();
    }

    void stopArm() {
        pinDriveBack.setLow();
        pinDriveForward.setLow();
    }

    void moveArmDown() {
        pinDriveBack.setHigh();
        pinDriveForward.setLow();
    }

    bool isSwitchOn() { return pinSwitch.isLow(); }

    bool isSwitchOff() { return !isSwitchOn(); }

    bool isArmDown() { return pinArmLowered.isHigh(); }

    bool isArmUp() { return !isArmDown(); }

};

#endif /* D29CD5B9_1CEA_4E6D_8441_E51E26206AC1 */
