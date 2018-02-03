#pragma once
#include <iostream>
#include <map>

using namespace std;

struct DbBase
{
    virtual int get_population(const std::string &name) = 0;
};

class SingletonDatabase : public DbBase
{
    SingletonDatabase() {
        capitals["Shanghai"] = 1000;
        capitals["Beijing"] = 2000;
    }
    std::map<std::string, int> capitals;

public:
    SingletonDatabase(SingletonDatabase const &) = delete;
    void operator = (SingletonDatabase const &) = delete;

    static SingletonDatabase &get() {
        static SingletonDatabase db; 
        return db;
    }

    int get_population(const std::string &name) override
    {
        return capitals[name];
    }
};
