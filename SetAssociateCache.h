#ifndef SETASSOCIATECACHE_H
#define SETASSOCIATECACHE_H
#include<unordered_map>
#include<iostream>
#include<queue>
#include<cmath>
#include<list>


class SetAssociateCache{
    std::unordered_map<int,std::list<int> > umap;
    int cacheSize;
    int cacheSizeBit;
    public: 
        SetAssociateCache(int);
        void MapAddr(int,int);
        int hit;
        int totalHit;

};






#endif
