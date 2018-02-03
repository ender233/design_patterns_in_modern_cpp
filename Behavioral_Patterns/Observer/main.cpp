#include <iostream>
#include <boost/signals2.hpp>
#include <boost/function.hpp>
#include <boost/bind.hpp>
using namespace boost::signals2;

class Ring
{
public:
    typedef signal<void()> signal_t;
    typedef signal_t::slot_type slot_t;

public:
    void press() {
        std::cout<<"Ring a alarms..."<<std::endl;
        alarm_();
    }
    void connect(const slot_t &s) {
        alarm_.connect(s);
    }

private:
    signal_t alarm_;
};

class Dog
{
public:
    void wangwangwang() {
        std::cout<<"wang wang wang!"<<std::endl;
    }
};

int main() {
    Ring r;
    Dog g;
    r.connect(boost::bind(&Dog::wangwangwang, &g));
    r.connect([](){std::cout<<"miaomiaomiao~"<<std::endl;});
    r.press();
}