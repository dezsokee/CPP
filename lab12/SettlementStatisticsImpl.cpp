#include <set>
#include <fstream>
#include <sstream>
#include "SettlementStatisticsImpl.h"

 typedef multimap<string, Settlement>::const_iterator MIT;

 int SettlementStatisticsImpl::numSettlements() const {
     return data.size();
}

int SettlementStatisticsImpl::numCounties() const {
    set<string> counties;

    for(auto &e : data) {
        counties.insert(e.first);
    }

    return counties.size();
}

int SettlementStatisticsImpl::numSettlementsByCounty(const string& county) const {
    vector<Settlement> settlements;

    pair<MIT, MIT> its = data.equal_range(county);

    for(auto it = its.first; it != its.second; it++) {
        settlements.push_back(it->second);
    }

    return settlements.size();
}

SettlementStatisticsImpl::SettlementStatisticsImpl(const string& fileName) {
     ifstream file;
     file.open(fileName);

    if (!file.is_open()) {
        cout << "File not found" << endl;
        return;
    }

    string line;
    string actualSettlementName;
    string actualCounty;
    int actualPopulation=0;

    int lineNumber = 0;

    while(getline(file, line)) {
        lineNumber++;

        if(lineNumber == 1) continue;

        istringstream inputStream(line);
        string token;

        getline(inputStream, actualSettlementName, ',');
        getline(inputStream, actualCounty, ',');
        getline(inputStream, token, ',');

        if(!token.empty()) {
            actualPopulation = stoi(token);
        }
        data.insert({actualCounty, Settlement(actualSettlementName, actualCounty, actualPopulation)});
    }

     file.close();
}

SettlementStatisticsImpl::~SettlementStatisticsImpl() {

}

vector<Settlement> SettlementStatisticsImpl::findSettlementsByCounty(const string &county) const {
    vector<Settlement> settlements;

    pair<MIT, MIT> its = data.equal_range(county);

    for(auto it = its.first; it != its.second; it++) {
        settlements.push_back(it->second);
    }

    return settlements;
}

Settlement SettlementStatisticsImpl::findSettlementsByNameAndCounty(const string &name, const string &county) const {
    vector<Settlement> settlements;

    pair<MIT, MIT> its = data.equal_range(county);

    for(auto it = its.first; it != its.second; it++) {
        settlements.push_back(it->second);
    }

    for(auto &actualSettlement : settlements) {
        if(actualSettlement.getName() == name)
            return actualSettlement;
    }
}

Settlement SettlementStatisticsImpl::maxPopulationDensity() const {
    int maxi = -1;
    Settlement actualSettlement2;

    for(const auto &settlement : data) {
        if(settlement.second.getPopulation() > maxi) {
            maxi = settlement.second.getPopulation();
            actualSettlement2 = settlement.second;
        }
    }

    return actualSettlement2;
}

Settlement SettlementStatisticsImpl::minPopulationDensity() const {
    int mini = INT_MAX;
    Settlement actualSettlement2;

    for(const auto &settlement : data) {
        if(settlement.second.getPopulation() < mini && settlement.second.getPopulation() != 0) {
            mini = settlement.second.getPopulation();
            actualSettlement2 = settlement.second;
        }
    }

    return actualSettlement2;
}

vector<Settlement> SettlementStatisticsImpl::findSettlementsByName(const string &name) {
    vector<Settlement> settlements;

    for(const auto &settlement : data) {
        if(settlement.second.getName() == name) {
            settlements.push_back(settlement.second);
        }
    }

    return settlements;
}








