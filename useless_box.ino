#include <Arduino.h>
//#include "src/SimpleCase.h"
#include "BoxDevice.h"
#include "HalfwayUseCase.h"

BoxDevice *device;
IUseCase *useCase = nullptr;

void setup() {
    Serial.begin(9600);
    device = new BoxDevice();
    Serial.println("Initialized.");
}

void loop() {
    delay(100);
    if (useCase == nullptr) useCase = new HalfwayUseCase(device);
    useCase->run();
}
