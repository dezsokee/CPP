#include <iostream>
#include "SettlementStatisticsImpl.h"

using namespace std;

int main() {
    SettlementStatisticsImpl settlementStatistics2("telepulesek.csv");

    cout<<"Number of settlements: " << settlementStatistics2.numSettlements()<<endl;
    cout<<"Number of counties: "<<settlementStatistics2.numCounties()<<endl<<endl;

    string county = "MS";

    cout<<"The number of settlements in "<<county<<" county is: " <<settlementStatistics2.numSettlementsByCounty(county)<<endl<<endl;

    cout<<"The names of the settlemets in "<<county<<" county are:"<<endl;
    vector<Settlement> settlements = settlementStatistics2.findSettlementsByCounty(county);

    for(const auto &settlement: settlements) {
        cout<<settlement<<endl;
    }
    cout<<endl;

    string settlement = "Targu Mures";

    cout<<"The settlement found by name and county is:"<<endl;
    cout<<settlementStatistics2.findSettlementsByNameAndCounty(settlement, county)<<endl;

    cout<<"Settlement with the maximum population is: "<< settlementStatistics2.maxPopulationDensity() <<endl;

    cout<<"Settlement with the minimum population is: "<< settlementStatistics2.minPopulationDensity() <<endl<<endl;

    string name = "Madaras";

    cout<<"The settlements found by name are:"<<endl;
    vector<Settlement> settlements2 = settlementStatistics2.findSettlementsByName(name);

    for(const auto &settlement: settlements2) {
        cout<<settlement<<endl;
    }

    return 0;
}