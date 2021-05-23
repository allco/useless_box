#ifndef HalfwayCase_h
#define HalfwayCase_h

#include "BoxDevice.h"
#include "Timer.h"
#include "IUseCase.h"

class HalfwayUseCase : public IUseCase {

private:
    BoxDevice *device;
    Timer *timer = nullptr;
    Timer *timer2 = nullptr;

public:
    explicit HalfwayUseCase(BoxDevice *device) {
        this->device = device;
        Serial.println("HalfwayUseCase initialized");
    }

    virtual ~HalfwayUseCase() {
        releaseTimers();
    }

    void run() override {
        if (device->isArmDown() && device->isSwitchOff()) {
            onStopArm();
        } else if (device->isArmUp() && device->isSwitchOff()) {
            onMoveArmDown();
        } else {
            onMoveArmUp();
        }
    }

    int cyclesFinished() override {
        return 0;
    }

public:

    void onMoveArmDown() {
        device->moveArmDown();
        releaseTimers();
    }

    void onStopArm() {
        device->stopArm();
        releaseTimers();
    }

    void onMoveArmUp() {
        if (timer == nullptr) {
            Serial.println("HalfwayUseCase timer create");
            timer = new Timer(200);
        }

        if (timer->isTimedOut()) {
            device->stopArm();
            if (timer2 == nullptr) timer2 = new Timer(1000);
            if (timer2->isTimedOut()) {
                device->moveArmUp();
            }
        } else {
            device->moveArmUp();
        }
    }

    void releaseTimers() {
        delete timer;
        delete timer2;
        timer = nullptr;
        timer2 = nullptr;
    }
};

#endif /* HalfwayCase_h */
