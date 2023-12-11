#ifndef LAB12_SETTLEMENTSTATISTICSIMPL_H
#define LAB12_SETTLEMENTSTATISTICSIMPL_H

#include <map>
#include "SettlementStatistics.h"

class SettlementStatisticsImpl : public SettlementStatistics {
    multimap<string, Settlement> data;

public:
    SettlementStatisticsImpl(const string& fileName);

    virtual ~SettlementStatisticsImpl();

    virtual int numSettlements() const override;

    virtual int numCounties() const override;

    virtual int numSettlementsByCounty(const string& county) const override;

    virtual vector<Settlement> findSettlementsByCounty (const string& county) const override;

    virtual Settlement findSettlementsByNameAndCounty(const string& name, const string& county) const override;

    virtual Settlement maxPopulationDensity() const override;

    virtual Settlement minPopulationDensity() const override;

    virtual vector<Settlement> findSettlementsByName(const string& name) override;
};


#endif //LAB12_SETTLEMENTSTATISTICSIMPL_H
