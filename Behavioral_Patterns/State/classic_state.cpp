//
// Created by ender on 2/7/18.
//

#include "classic_state.hpp"

void State::on(LightSwitch *ls) {
    std::cout<<"Light is already on\n";
}
void State::off(LightSwitch *ls) {
    std::cout<<"Light is already off\n";
}


OffState::OffState() {std::cout<<"Light turned off\n";}
OnState::OnState() {std::cout<<"Light turn on\n";}
void OffState::on(LightSwitch *ls)
{
    std::cout<<"Switching Light on\n";
    ls->set_state(new OnState());
}
void OnState::off(LightSwitch *ls)
{
    std::cout<<"Switching Light off\n";
    ls->set_state(new OffState());
}

LightSwitch::LightSwitch() {state = new OffState();}



