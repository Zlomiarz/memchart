#pragma once

#include <string>
#include <vector>

#include "MemTracer.h"

class StatisticData{
    public:
        StatisticData(const std::string& name_);
        StatisticData();
        virtual ~StatisticData();
        
        bool isEnabled(){
            return enabled;
        }
        void setEnabled(bool e=true){
            enabled = e;
        }
        
        void update(MemTracer& mem);
    //protected:
        std::vector<double> allocations;
        std::vector<double> allocatedMem;
        std::vector<double> newCounter;
        std::vector<double> deleteCounter;
        std::string name;
        bool enabled;
    private:
};
