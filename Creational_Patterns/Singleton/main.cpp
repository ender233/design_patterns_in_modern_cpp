#include <iostream>
#include "dbSingleton.hpp"
#include <vector>

#define CATCH_CONFIG_MAIN
#include <catch.hpp>
//#include <fakeit.hpp>

// class to be tested
struct ConfigurableRecordFinder
{
    DbBase &db;
    explicit ConfigurableRecordFinder(DbBase &db) : db(db) {}
    int total_population(std::vector<std::string> names) const {
        int result(0);
        for(auto &name : names) {
            result += db.get_population(name);
        }
        return result;
    }
};

// Mock Class
class DataBaseMock : public DbBase
{
    std::map<std::string, int> capitals;
public:
    DataBaseMock() {
        capitals["Shanghai"] = 2000;
        capitals["Beijing"] = 1000;
    }

    int get_population(const std::string &name) override {
        return capitals[name];
    }
};

// DummyMock
TEST_CASE("ConfigurableRecordFinder", "total_population")
{
    DataBaseMock dbmock;
    ConfigurableRecordFinder finder(dbmock);
    std::vector<std::string> names{"Beijing", "Shanghai"};
    REQUIRE(3000 == finder.total_population(names));
}

// Mock with Fakeit
/*
TEST_CASE("ConfigurableRecordFinder2", "total_population")
{
    using namespace fakeit;
    Mock<DbBase> mock;
    When(Method(mock,get_population)("Shanghai")).Return(2000);
    When(Method(mock,get_population)("Beijing")).Return(1000);
    ConfigurableRecordFinder finder(mock.get());
    std::vector<std::string> names{"Beijing", "Shanghai"};
    REQUIRE(3000 == finder.total_population(names));
}
*/

TEST_CASE("", "")
{
    // common use
    std::cout<<"Beijing:"
             << SingletonDatabase::get().get_population(std::string("Beijing"))
             << std::endl;
}

