#ifndef SETASSOCIATENOT
#define SETASSOCIATENOT
#include<cmath>
#include<unordered_map>
#include<list>
#include<string>


class SetAssociateNot{
      std::unordered_map<int,std::list<int> > umap;
    int cacheSize;
    int cacheSizeBit;
    public: 
        SetAssociateNot(int);
        void MapAddr(int,int,std::string);
        int hit;
        int totalHit;
};

#endif