#include <iostream>
#include <vector>
#include <string>
#include "classic_state.hpp"

// non-state
enum LIGHT_STATE {
    LIGHT_ON,
    LIGHT_OFF
};

struct LightSwitch2 {
    LIGHT_STATE state_;
    LightSwitch2() : state_(LIGHT_OFF) {}

    void on() {
        if(state_ == LIGHT_OFF) {
            std::cout<<"Switching Light on\n";
            state_ = LIGHT_ON;
        }
        else
            std::cout<<"Light turn on\n";
    }
    void off() {
        if(state_ == LIGHT_ON){
            std::cout<<"Switching Light off\n";
            state_ = LIGHT_OFF;
        }
        else {
            std::cout<<"Light turn off\n";
        }
    }
};

int main() {
    // non-state
    LightSwitch2 ls2;
    ls2.on();
    ls2.off();
    ls2.off();
    std::cout<<std::endl;

    // classic State Design Pattern
    std::cout<<"LightSwitch begin...";
    LightSwitch *ls = new LightSwitch();
    ls->on();
    ls->off();
    ls->off();
    return 0;
}