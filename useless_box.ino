#include <Arduino.h>
//#include "src/SimpleCase.h"
#include "src/BoxDevice.h"
#include "src/HalfwayUseCase.h"

BoxDevice *device;
IUseCase *useCase = nullptr;

void setup() {
    Serial.begin(9600);
    device = new BoxDevice();
    Serial.println("Initialized.");
}

void loop() {
    if (useCase == nullptr) useCase = new HalfwayUseCase(device);
    useCase->run();
}
