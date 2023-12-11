#ifndef LAB12_SETTLEMENT_H
#define LAB12_SETTLEMENT_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Settlement {
    string name = "";
    string county = "";
    int population = 0;

public:
    Settlement(const string &name, const string &county, int population) : name(name), county(county), population(population) {};

    Settlement(){};

    const string &getName() const {
        return name;
    }

    void setName(const string &name) {
        Settlement::name = name;
    }

    const string &getCounty() const {
        return county;
    }

    void setCounty(const string &county) {
        Settlement::county = county;
    }

    int getPopulation() const {
        return population;
    }

    void setPopulation(int population) {
        Settlement::population = population;
    }

    friend ostream& operator<<(ostream& os, const Settlement& settlement) {
        os << "Name: " << settlement.name << ", County: " << settlement.county << ", Population: " << settlement.population;
        return os;
    }

    Settlement& operator=(Settlement settlement2) {
        this->name = settlement2.name;
        this->county = settlement2.county;
        this->population = settlement2.population;
        return *this;
    }
};

#endif //LAB12_SETTLEMENT_H
