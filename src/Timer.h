#ifndef USELESS_BOX_TIMER_H
#define USELESS_BOX_TIMER_H

class Timer {
    unsigned long timeoutAt = 0;

public:
    explicit Timer(int timeoutMs) {
        unsigned long currentTime = millis();
        timeoutAt = timeoutMs + currentTime;
        Serial.print("Timer created:");
        Serial.println((unsigned long) this);
    }

    virtual ~Timer() {
        Serial.print("Timer destroyed:");
        Serial.println((unsigned long) this);
    }

    bool isTimedOut() const { return millis() > timeoutAt; }
};

#endif //USELESS_BOX_TIMER_H