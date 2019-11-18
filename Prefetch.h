#ifndef PREFETCH_H
#define PREFETCH_H
#include<unordered_map>
#include<iostream>
#include<queue>
#include<cmath>
#include<list>

class Prefetch{
    std::unordered_map<int,std::list<int> > umap;
    int cacheSize;
    int cacheSizeBit;
    public: 
        Prefetch(int);
        void MapAddr(int,int,int,bool loadFlag = true);
        int hit;
        int totalHit;

};

#endif
