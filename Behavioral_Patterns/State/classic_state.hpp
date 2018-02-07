//
// Created by ender on 2/6/18.
//
#ifndef STATE_CLASSIC_STATE_HPP
#define STATE_CLASSIC_STATE_HPP
#include <iostream>

class LightSwitch;
struct State
{
    virtual void on(LightSwitch *ls);
    virtual void off(LightSwitch *ls);
};

class OffState : public State
{
public:
    OffState();
    virtual void on(LightSwitch *ls) override;
};
class OnState : public State
{
public:
    OnState();
    virtual void off(LightSwitch *ls) override;
};


class LightSwitch
{
    State *state;
public:
    LightSwitch();
    void set_state(State *state) {
        this->state = state;
    }

    void on() {state->on(this);}
    void off() {state->off(this);}
};

#endif //STATE_CLASSIC_STATE_HPP
