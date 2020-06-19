#pragma once
#include <iostream>
#include <string>
using namespace std;

class Strategy
{
public:
    virtual ~Strategy() {}
    virtual void applySettings() const = 0;
};


class Context
{
    Strategy* strategy;
public:
    Context(Strategy* strategy = nullptr) : strategy(strategy)
    {
    }
    ~Context()
    {
        delete this->strategy;
    }

    void set_strategy(Strategy* strategyy)
    {
        delete this->strategy;
        this->strategy = strategyy;
    }

    void chooseSettings()
    {
        this->strategy->applySettings();
    }
};


class NormalSettings : public Strategy
{
public:
    void applySettings() const {
        cout << "Settings level is set to normal" << endl;
        cout << "Resolution is set to 1920x1080" << endl;
        cout << "Textures are set to medium" << endl;
        cout << "Advanced water effects are disabled" << endl;
        cout << "Advanced fog is disabled" << endl;
        cout << "Shadows: normal" << endl;
        cout << "Detalization:normal" << endl;
    }
};

class HighSettings : public Strategy
{
public:
    void applySettings() const {
        cout << "Settings level is set to high" << endl;
        cout << "Resolution is set to 2560x1440" << endl;
        cout << "Textures are set to high" << endl;
        cout << "Advanced water effects are enabled" << endl;
        cout << "Advanced fog is disabled" << endl;
        cout << "Shadows: high" << endl;
        cout << "Detalization:high" << endl;
    }
};

class UltraSettings : public Strategy
{
public:
    void applySettings() const {
        cout << "Settings level is set to ultra" << endl;
        cout << "Resolution is set to 3840x2160" << endl;
        cout << "Textures are set to ultra" << endl;
        cout << "Advanced water effects are enabled" << endl;
        cout << "Advanced fog is enabled" << endl;
        cout << "Shadows: ultra" << endl;
        cout << "Detalization:ultra" << endl;
    }
};

