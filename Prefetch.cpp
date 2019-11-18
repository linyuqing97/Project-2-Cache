#include "Prefetch.h"
#include "Prefetch.h"



using namespace std;

#define cacheLineSize (32)

Prefetch::Prefetch(int cacheSize){
    this->cacheSize = cacheSize;
    umap.clear();
}

void Prefetch::MapAddr(int address,int set,int option = 0,bool loadFlag ){
    this->totalHit++;
    int offsetSize = 5;
	int blockSize = log2 (this->cacheSize / (cacheLineSize*set)); 
	int block = (address >> offsetSize);
	int mask = ((0x1 << blockSize) - 1); 
	block = block & mask;

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
	
	
	//prefetch
	int tempAddress = address+32;
	int tempBlockSize = log2 (this->cacheSize / (cacheLineSize*set)); 
	int tempBlock = (tempAddress >> offsetSize);
	int tempMask = ((0x1 << tempBlockSize) - 1); 
	tempBlock = tempBlock & tempMask;

	int tempTag = tempAddress >> (offsetSize + tempBlockSize); 
	if (umap.find(tempBlock)!=umap.end()){
		bool found = false;
		for(list<int>::iterator it = umap[tempBlock].begin(); it != umap[tempBlock].end(); it++){
			if(*it == tempTag){
				umap[tempBlock].remove(tempTag);
				umap[tempBlock].push_back(tempTag);
				found = true;

				break;
			}
		}
		if(!found){
				if(umap[tempBlock].size()<set)umap[tempBlock].push_back(tempTag);
				else{
					umap[tempBlock].pop_front();
					umap[tempBlock].push_back(tempTag);
				}
			}
	
	}
	else{
				umap[tempBlock].push_back(tempTag);
	} 
	
}