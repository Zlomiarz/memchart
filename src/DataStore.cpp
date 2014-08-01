#include "DataStore.h"

DataStore::DataStore():nextime(0){
    
    data["radio"] = new StatisticData("radio");
    data["rp1"] = new StatisticData("rp1");
    data["rp3"] = new StatisticData("rp3");
    data["all"] = new StatisticData("all");
}

DataStore::~DataStore()
{
    //dtor
}

void DataStore::update(){
    time_vec.push_back(nextime++);
    for (auto e:data){
        e.second->update(memTracer);
    }
}

std::vector<std::string> DataStore::getComponents(){
    std::vector<std::string> ret;
    for (dataIt it = data.begin(); it != data.end(); ++it){
        ret.push_back(it->first);
    }
    return ret;
}
