#ifndef HOTCOLD_H
#define HOTCOLD_H

#include<vector>
#include<cmath>

class HotCold{
private:
    int *hotColdTable;
    int * addressTable;
    int cacheSize;
public:
    
    HotCold(int);
    void MapAddr(int);
    void update(int index);
    int hit;
    int totalHit;
    
    ~HotCold(){
       delete hotColdTable;
       delete addressTable;
    }

};







#endif