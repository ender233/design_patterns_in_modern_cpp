#include <iostream>

using namespace std;

struct Game
{
    explicit Game(int number_of_players):
        number_of_players(number_of_players)
    {

    }
    void run() {
        start(); 
        while(!have_winner()) 
            take_turn();
        cout<<"Player "<< get_winner()<<" wins.\n";
    }

protected:
    virtual void start() = 0;
    virtual bool have_winner() = 0;
    virtual void take_turn() = 0;
    virtual int get_winner() = 0;

    int number_of_players;
    int current_player;
};

class Chess : public Game
{
public:
    explicit Chess() : Game(2) {}

protected:
    void start() override{
        cout<<"Starting a game of chess with 2 players" <<endl;
    }
    bool have_winner() override {return turns == max_turns;}
    void take_turn() override {
        turns++; 
        current_player = (current_player + 1) % number_of_players;
        cout<<"Turn "<<turns<<" taken by player:"<<current_player<<endl;
    }
    int get_winner() override {return current_player;}
private:
    int turns{0};
    int max_turns{10};
};

int main()
{
    Chess c1;
    c1.run();
}


