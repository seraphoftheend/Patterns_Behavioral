#pragma once
#include <iostream>
#include <string>
using namespace std;

class Component;
class Mediator {
public:
    virtual void Notify(Component* sender, string event, float result) const = 0;
};


class Component {
protected:
    Mediator* mediator;
public:
    Component(Mediator* mediatorr = nullptr) : mediator(mediatorr) {
    }
    void set_mediator(Mediator* mediatorr) {
        this->mediator = mediatorr;
    }
};


class ADC : public Component {
public:
    void doMeasurement() {
        std::cout << "ADC did a measurement\n";
        this->mediator->Notify(this, "measurement", 3674);
    }
};

class AnalogTemperatureSensor : public Component {
    uint16_t rawValue = 0;
public:
    float getCelsius() {
        static uint16_t Vo = 0;
        static float R1 = 10000;
        static float logR2 = 0, R2 = 0, T = 0, k = 40;
        static float c1 = 0.001129148, c2 = 0.000234125, c3 = 0.0000000876741;     //steinhart-hart coeficients for thermistor
        Vo = rawValue;
        R2 = R1 / (4095.0 / (float)Vo - 1.0);    //calculate resistance on thermistor
        logR2 = log(R2);
        T = (1.0 / (c1 + c2 * logR2 + c3 * logR2 * logR2 * logR2)) + k;    // temperature in Kelvin
        T -= 273.15;
        this->mediator->Notify(this, "celsius", T);
        return T;
    }
    void setRawData(uint16_t data) {
        this->rawValue = data;
        this->mediator->Notify(this, "temperatureSet", 1);
    }
};


class Indicators :public Component {
    bool ledOn[3] = { 0 };
public:
    void setIndicators(bool cold, bool normal, bool hot) {
        ledOn[0] = cold;
        ledOn[1] = normal;
        ledOn[2] = hot;
        this->mediator->Notify(this, "indicatorsSet", 1);
    }

    void turnOnIndicators() {
        if (ledOn[0]) {
            cout << "Is cold" << endl;
        }
        if (ledOn[1]) {
            cout << "Is normal" << endl;
        }
        if (ledOn[2]) {
            cout << "Is hot" << endl;
        }
        this->mediator->Notify(this, "indicatorsTurnedOn", 1);
    }
};


class ConcreteMediator : public Mediator {
private:
    ADC* adc_;
    AnalogTemperatureSensor* analogTemperatureSensor;
    Indicators* indicators;

public:
    ConcreteMediator(ADC* c0, AnalogTemperatureSensor* c1, Indicators* c2) : adc_(c0), analogTemperatureSensor(c1), indicators(c2) {
        this->adc_->set_mediator(this);
        this->analogTemperatureSensor->set_mediator(this);
        this->indicators->set_mediator(this);
    }
    void Notify(Component* sender, string event, float result) const override {
        if (event == "measurement") {
            this->analogTemperatureSensor->setRawData(result);
            float tmp = analogTemperatureSensor->getCelsius();
            cout << "Current temperature is: \n" << tmp << " Celsius" << endl;
            if (tmp < 18) {
                this->indicators->setIndicators(true, false, false);
            }
            if (tmp < 24) {
                this->indicators->setIndicators(false, true, false);
            }
            if (tmp > 24) {
                this->indicators->setIndicators(false, false, true);
            }
            this->indicators->turnOnIndicators();
        }
        if (event == "temperatureSet") {
            cout << "Temperature is set successfully\n";
        }
        if (event == "celsius") {
            cout << "Temperature is successfully converted to Celsius\n";
        }
        if (event == "indicatorsSet") {
            cout << "Indicators are set successfully\n";
        }
        if (event == "indicatorsTurnedOn") {
            cout << "Indicators are turned on\n";
        }
    }
};

