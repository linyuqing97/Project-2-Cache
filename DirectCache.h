#ifndef DIRECTCACHE_H
#define DIRECTCACHE_H
#include<unordered_map>
#include<cmath>


class DirectCache{
    std::unordered_map<int,int>umap;
    int cacheSize;
    int cacheSizeBit;
    public: 
        DirectCache(int);
        void MapAddr(unsigned long long);
        int hit;
        int totalHit;

};






#endif
