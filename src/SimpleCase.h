#include "BoxDevice.h"

#ifndef SimpleCase_h
#define SimpleCase_h

class SimpleCase {

private:
    BoxDevice *device;

public:
    SimpleCase(BoxDevice *device) {
        this->device = device;
    }

    void run() {
        if (device->isArmDown() && device->isSwitchOff()) {
            device->stopArm();
        } else if (device->isArmUp() && device->isSwitchOff()) {
            device->moveArmDown();
        } else {
            device->moveArmUp();
        }
    }
};

#endif /* SimpleCase_h */
