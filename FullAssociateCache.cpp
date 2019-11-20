#include "FullAssociateCache.h"
#include "FullAssociateCache.h"

using namespace std;

#define cacheLineSize (32)

FullAssociateCache::FullAssociateCache(int cacheSize){
    this->cacheSize = cacheSize;
    this->hit = 0;
	this->totalHit = 0;
}
void FullAssociateCache::MapAddr(int address){
    this->totalHit++;
    int offsetSize = 5;
	int block = this->cacheSize >> offsetSize; 
	int tag = address >> (offsetSize); 
    
    for(list<int>::iterator it = myList.begin(); it != myList.end(); it++){
        bool found = false;
		if(*it == tag){
				hit++;
				myList.remove(tag);
			    myList.push_back(tag);
				found = true;
				return;
			}
		}
		if(myList.size()>=block)myList.pop_front();
		myList.push_back(tag);
}