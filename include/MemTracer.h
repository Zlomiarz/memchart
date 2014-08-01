#pragma once

#include <map>
#include <string>
#include <vector>

class MemInfo{
    public:
        MemInfo(){}
        ~MemInfo(){}
        
    protected:
        void* prt;
        size_t size;
        std::string component;
        std::vector<std::string> stack;
};

class MemTracer
{
    public:
        MemTracer();
        virtual ~MemTracer();
        
        int getAllocations(const std::string &component){
            if (component == "all"){
                int ret = 0;
                for (auto &e: allocations){
                    ret += e.second;
                }
                return ret;
            }
            return allocations[component];
        }
        
        int getAllocatedMem(const std::string &component){
            if (component == "all"){
                int ret = 0;
                for (auto &e: allocatedMem){
                    ret += e.second;
                }
                return ret;
            }
            return allocatedMem[component];
        }
        
        int getNewCalls(const std::string &component){
            if (component == "all"){
                int ret = 0;
                for (auto &e: newCounter){
                    ret += e.second;
                }
                return ret;
            }
            return newCounter[component];
        }
        
        int getDeleteCalls(const std::string &component){
            if (component == "all"){
                int ret = 0;
                for (auto &e: deleteCounter){
                    ret += e.second;
                }
                return ret;
            }
            return deleteCounter[component];
        }
        
        void resetNewDelete(){
            for (auto &e: deleteCounter){
                e.second = 0;
            }
            for (auto &e: newCounter){
                e.second = 0;
            }
        }
    protected:
        typedef std::map<std::string, int> ComponentAllocations;
        ComponentAllocations allocations;
        ComponentAllocations allocatedMem;
        ComponentAllocations newCounter;
        ComponentAllocations deleteCounter;
        
        std::map<void*, MemInfo*> allocationsMap;
    private:
};
