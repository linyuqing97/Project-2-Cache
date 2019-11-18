#ifndef FULLASSOCIATECACHE_H
#define FULLASSOCIATECACHE_H
#include<iostream>
#include<cmath>
#include<list>
#include <unordered_map>


class FullAssociateCache{
   std::list<int> myList;
    int cacheSize;
    
    int cacheSizeBit;
    public:
        FullAssociateCache(int);
        void MapAddr(int);
        int hit;
        int totalHit;

};






#endif