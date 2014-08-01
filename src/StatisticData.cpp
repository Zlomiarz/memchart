#include "StatisticData.h"

StatisticData::StatisticData(const std::string& name_):name(name_),enabled(true)
{
    //ctor
}
StatisticData::StatisticData()
{
    //ctor
}

StatisticData::~StatisticData()
{
    //dtor
}

void StatisticData::update(MemTracer& mem){
    allocatedMem.push_back(rand()%5+3);
}
