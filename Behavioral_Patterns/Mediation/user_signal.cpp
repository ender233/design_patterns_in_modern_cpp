#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include <boost/signals2/signal.hpp>
using namespace std;
using namespace boost::signals2;

// Message
struct EventMessage {
    virtual ~EventMessage() = default;
    virtual void showMessage() const = 0;
};
struct ChatMessage : public EventMessage {
    string username;
    string message;
    ChatMessage(const string &username, const string &message) : username(username), message(message) {}

    void showMessage() const override {
        std::time_t now = std::time(nullptr);
        std::cout << std::put_time(std::localtime(&now), "%Y-%m-%d %H:%M:%S") << "[" << username << "]: " << message << std::endl;
    }
};

// EventBus -> ChatRoom
struct EventBus {
    signal<void(EventMessage *)> sig;
    EventBus() {
        sig.connect([](EventMessage *e){
            ChatMessage *mess = dynamic_cast<ChatMessage *>(e);
            if(mess) {
                mess->showMessage();
            }});
    }
};

// instance
struct User {
    string   name_;
    EventBus &event;

    User(const string &name_, EventBus &event) : name_(name_), event(event) {
    }

    void send(const string &message) {
        ChatMessage chatMessage(name_, message);
        event.sig(&chatMessage);
    }
};

int main() {
    EventBus bus;
    User john("John Doe", bus);
    User jane("Jane Doe", bus);

    john.send("Hi, there!");
    jane.send("Hey!");
}
