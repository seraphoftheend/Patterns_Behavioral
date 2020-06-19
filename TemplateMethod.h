#pragma once
#include <iostream>
#include <string>
using namespace std;

class ConfigurePC {
protected:
    virtual void chooseCPU() const = 0;
    virtual void chooseMotherBoard() const = 0;
    virtual void chooseCooler() const = 0;
    virtual void chooseRAM() const { cout << "RAM: 8 Gb x 2 pc.  Ballistix BLS2K8G4D32AESBK" << endl; };
    virtual void chooseDiscreteGPU() const {};
    virtual void choosePSU() const = 0;
    virtual void chooseCase() const { cout << "Case: Zalman Z3 Black" << endl; };

public:
    void TemplateMethod() const {
        this->chooseCPU();
        this->chooseMotherBoard();
        this->chooseCooler();
        this->chooseRAM();
        this->chooseDiscreteGPU();
        this->choosePSU();
        this->chooseCase();
    }
};

class AdvancedPC : public ConfigurePC {
protected:
    void chooseCPU() const override {
        cout << "CPU: Ryzen 9 3900X / 3950X" << endl;
    }
    void chooseMotherBoard() const override {
        cout << "MB based on chipset: Z490 (ASUS, MSI, ASRock) " << endl;
    }
    void chooseCooler() const override {
        cout << "Cooler: Noctua D15" << endl;
    }
    void choosePSU() const override {
        cout << "PSU: Seasonic FOCUS Plus Gold 750W" << endl;
    }
    void chooseDiscreteGPU() const {
        cout << "GPU: RTX 2080 Super / 2080 Ti" << endl;
    }
    void chooseRAM() const override {
        cout << "RAM: 16 Gb x 2 pc.  Ballistix BLS2K8G4D32AESBK" << endl;
    }
};


class BudgetPC : public ConfigurePC {
protected:
    void chooseCPU() const override {
        cout << "CPU: AMD Ryzen 3 2200G / 3200G" << endl;
    }
    void chooseMotherBoard() const override {
        cout << "MB based on chipset: A320 / B350 / B450" << endl;
    }
    void chooseCooler() const override {
        cout << "Cooler: Deepcool GAMMAXX L240T WHITE" << endl;
    }
    void choosePSU() const override {
        cout << "PSU: Corsair VS450 450W" << endl;
    }
};
/**
 * Клиентский код вызывает шаблонный метод для выполнения алгоритма. Клиентский
 * код не должен знать конкретный класс объекта, с которым работает, при
 * условии, что он работает с объектами через интерфейс их базового класса.
 */

void ClientCode(ConfigurePC* class_) {
    class_->TemplateMethod();
}

