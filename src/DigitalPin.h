#ifndef ADE05690_B09D_405C_81B8_AEEDDDEAF2CA
#define ADE05690_B09D_405C_81B8_AEEDDDEAF2CA

class DigitalInputPin {
private:
    int pin;

public:
    DigitalInputPin(int pin) {
        this->pin = pin;
        pinMode(pin, INPUT); // arm
    }

    bool isHigh() { return digitalRead(pin) == HIGH; }

    bool isLow() { return !isHigh(); }
};

class DigitalOutputPin {
private:
    int pin;

public:
    DigitalOutputPin(int pin) {
        this->pin = pin;
        pinMode(pin, OUTPUT); // arm
    }

    void setHigh() { digitalWrite(pin, HIGH); }

    void setLow() { digitalWrite(pin, LOW); }
};

#endif /* ADE05690_B09D_405C_81B8_AEEDDDEAF2CA */
