#include <iostream>
#include <vector>
#include <string>
#include "classic_state.hpp"

// back-end
#include <boost/msm/back/state_machine.hpp>
// front-end
#include <boost/msm/front/state_machine_def.hpp>
#include <boost/msm/front/functor_row.hpp>

/*
namespace msm = boost::msm;
namespace mpl = boost::mpl;
using namespace msm::front;
using namespace std;

vector<string> state_names{
        "off hook"s,
        "connecting"s,
        "connected"s,
        "on hold"s,
        "destroyed"s
};
enum class State {
    off_hook,
    connecting,
    connected,
    on_hold,
    on_hook
};
struct CallDialed{};
struct HungUp{};
struct CallConnected {};
struct PlaceOnHold{};
struct TakeOffHold{};
struct LeftMessage{};
struct PhoneThrownIntoWall{};

struct PhoneStateMachine : state_machine_def<PhoneStateMachine> {
    struct off_hook : state<> {};
    struct connecting : state<> {
        // No override??
        template <class Event, class FSM>
        void on_entry(const Event &event, FSM &fsm) {

        }
    };
};
 */

int main() {
    // classic State Design Pattern
    std::cout<<"LightSwitch begin...";
    LightSwitch *ls = new LightSwitch();
    ls->on();
    ls->off();
    ls->off();
    return 0;
}