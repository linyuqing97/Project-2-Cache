#include "SetAssociateCache.h"


using namespace std;

#define cacheLineSize (32)

SetAssociateCache::SetAssociateCache(int cacheSize){
    this->cacheSize = cacheSize;
    umap.clear();
}

void SetAssociateCache::MapAddr(int address,int set){
    this->totalHit++;
    int offsetSize = 5;
	int blockSize = log2 (this->cacheSize / (cacheLineSize*set)); 
	int block = (address >> offsetSize) & ((0x1 << blockSize) - 1); 
	int tag = address >> (offsetSize + blockSize); 
	if (umap.find(block)!=umap.end()){
		bool found = false;
		for(list<int>::iterator it = umap[block].begin(); it != umap[block].end(); it++){
			if(*it == tag){
				hit++;
				umap[block].remove(tag);
				umap[block].push_back(tag);
				found = true;
				break;
			}
		}
		if(!found){
				if(umap[block].size()<set)umap[block].push_back(tag);
				else{
					umap[block].pop_front();
					umap[block].push_back(tag);
				}
			}
	
	}
	else{
				umap[block].push_back(tag);
	} 
}