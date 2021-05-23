#ifndef HalfwayCase_h
#define HalfwayCase_h

#include "BoxDevice.h"
#include "Timer.h"
#include "IUseCase.h"

class HalfwayUseCase : public IUseCase {

private:
    BoxDevice *device;
    Timer *timer = nullptr;

public:
    explicit HalfwayUseCase(BoxDevice *device) {
        this->device = device;
        Serial.println("HalfwayUseCase initialized");
    }

    virtual ~HalfwayUseCase() {
        releaseTimer();
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
        releaseTimer();
    }

    void onStopArm() {
        device->stopArm();
        releaseTimer();
    }

    void onMoveArmUp() {
        if (timer == nullptr) {
            Serial.println("HalfwayUseCase timer create");
            timer = new Timer(100);
        }

        if (timer->isTimedOut()) {
            device->stopArm();
        } else {
            device->moveArmUp();
        }
    }

    void releaseTimer() {
        delete timer;
        timer = nullptr;
        Serial.println("HalfwayUseCase timer release");
    }
};

#endif /* HalfwayCase_h */
