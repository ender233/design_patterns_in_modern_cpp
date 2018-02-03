#include <iostream>
#include <string>
#include <boost/signals2/signal.hpp>
using namespace std;
using namespace boost::signals2;

// message
struct EventData {
    virtual ~EventData() = default;
    virtual void print() const = 0;
};

struct PlayerScoreData : EventData {
    string player_name;
    int goals_scored_so_far;

    PlayerScoreData(const string &player_name, int goals_scored_so_far) : player_name(player_name),
                                                                          goals_scored_so_far(goals_scored_so_far) {}

    void print() const override {
        cout<< player_name <<" has scored!(their"<<goals_scored_so_far<<" goals)"<<endl;
    }
};

struct Game{
    signal<void(EventData *)> events;
};

// instance
struct Player {
    string name;
    int goals_scored = 0;
    Game &game;

    Player(const string &name, Game &game) : name(name), game(game) {}
    void score() {
        ++goals_scored;
        PlayerScoreData ps(name, goals_scored);
        game.events(&ps);
    }
};

struct Coach {
    Game &game;
    explicit Coach(Game &game) : game(game) {
        game.events.connect([](EventData *e){
            PlayerScoreData *ps = dynamic_cast<PlayerScoreData*>(e);
            if(ps && ps->goals_scored_so_far < 3) {
                cout<<"coach says: well done, "<<ps->player_name<<"\n";
            }
        });
    }
};

int main() {
    Game game;
    Player p1("Sam", game);
    Coach coach(game);

    p1.score();
    p1.score();
    p1.score();
}