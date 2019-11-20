#include"DirectCache.h"
#include"DirectCache.h"

using namespace std;

#define cacheLineSize (32)

DirectCache::DirectCache(int cacheSize){
    this->cacheSize = cacheSize;
	this->hit = 0;
	this->totalHit = 0;
    umap.clear();
}

void DirectCache::MapAddr(unsigned long long address){
    this->totalHit++;
    
    int offsetSize = 5; 
	int blockSize = log2 (this->cacheSize / cacheLineSize); 
	unsigned long block = (address >> offsetSize) & ((0x1 << blockSize) - 1); 
	unsigned long tag = address >> (offsetSize + blockSize); 

	if (umap.find(block)!=umap.end() && umap[block] == tag)  
		hit++;
	else {  
			umap[block]= tag;
		}

	

}