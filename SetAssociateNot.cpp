#include "SetAssociateNot.h"


using namespace std;

#define cacheLineSize (32)

SetAssociateNot:: SetAssociateNot(int cacheSize){
    this->cacheSize = cacheSize;
	this->hit = 0;
	this->totalHit = 0;
    umap.clear();
} 


void SetAssociateNot:: MapAddr(int address,int set,string loadFlag ){
    this->totalHit++;
    int offsetSize = 5;
	int blockSize = log2 (this->cacheSize / (cacheLineSize*set)); 
	int mask = ((0x1 << blockSize) - 1);
	int block = (address >> offsetSize) & mask; 
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
		//cout<<loadFlag<<endl;
		if(!found && loadFlag == "L"){
				if(umap[block].size() < set)umap[block].push_back(tag);
				else{
					umap[block].pop_front();
					umap[block].push_back(tag);
				}
			}
		
	}
	else{
		   if(loadFlag == "L"){
			umap[block].push_back(tag);
		} 
}
}