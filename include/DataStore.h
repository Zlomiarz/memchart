#pragma once

#include <vector>
#include <string>
#include "StatisticData.h"

class DataStore
{
    public:
        static DataStore* getInstance(){
            static DataStore instance;
            return &instance;
        }
        
        void update();
        void reset();
        
        std::vector<double>& getTimeVector(){
            return time_vec;
        }
        
        std::vector<std::string> getComponents();
        
        StatisticData* getStatisticsData(const std::string& name){
            return data[name];
        }
        
        MemTracer* getMemTracer(){
            return &memTracer;
        }
        
        void enableStatisticData(const std::string &name, bool t=true){
            data[name]->setEnabled(t);
        }
        
    protected:
        DataStore();
        virtual ~DataStore();
        
        typedef std::map<std::string, StatisticData*>::iterator dataIt;

        MemTracer memTracer;
        std::map<std::string, StatisticData*> data;
        std::vector<double> time_vec;
        int nextime;
        
    private:
};
