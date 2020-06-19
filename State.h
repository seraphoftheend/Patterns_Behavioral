#pragma once
#include <iostream>
#include <string>
using namespace std;

class AlertStateContext;

class AlertState {
protected:
    AlertStateContext* context_;

public:
    virtual ~AlertState() {
    }

    void set_context(AlertStateContext* context) {
        this->context_ = context;
    }

    virtual void alert() = 0;
};


class AlertStateContext {
private:
    AlertState* state_;

public:
    AlertStateContext(AlertState* state) : state_(nullptr) {
        this->TransitionTo(state);
    }
    ~AlertStateContext() {
        delete state_;
    }

    void TransitionTo(AlertState* state) {
        cout << "Context: Transition to " << typeid(*state).name() << endl;
        if (this->state_ != nullptr)
            delete this->state_;
        this->state_ = state;
        this->state_->set_context(this);
    }
 
    void Notification() {
        this->state_->alert();
    }
};


class SilentMode : public AlertState {
public:
    void alert() override {
        cout << "Silent notification without sound and vibration" << endl;
    }
};

class NormalMode : public AlertState {
public:
    void alert() override {
        cout << "Regular notification with sound and vibration" << endl;
    }
};

