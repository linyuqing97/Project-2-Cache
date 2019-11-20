#include "HotCold.h"
#include "HotCold.h"
#include <iostream>

using namespace std;

HotCold::HotCold(int cacheSize){
    this->cacheSize = cacheSize/32;
    this->totalHit = 0;
    this->hit = 0;
    this->hotColdTable = new int[cacheSize-1]();
    this->addressTable = new int[cacheSize]();
    for(int i = 0 ;i <512;i++){
        this->addressTable[i]= -1;//-1
    }
}
void HotCold::update(int indexOfFound){

   
        while(indexOfFound>0){ //=0
            if(indexOfFound %2 ==0){
                hotColdTable[(indexOfFound-2)/2] = 1;
                   indexOfFound = (indexOfFound-2)/2;

            }
            else if(indexOfFound %2 ==1){
                hotColdTable[(indexOfFound-1)/2] = 0;
                      indexOfFound = (indexOfFound-1)/2;
                
            }
        }
}
void HotCold::MapAddr(int address){
    this->totalHit++;
    int offsetSize = 5;
	int tag = address >> (offsetSize); 

    bool found = false;
    int indexOfFound = 0;

    for(int i = 0;i<512; i ++){
        if(addressTable[i] == tag ){
            hit++;
            found = true;
            indexOfFound = i;
            break;
        }
    }
    if(found){
        int treeIndex = indexOfFound+511;
        update(treeIndex);
    }

    if(!found){
        int childIndex = 0;
        for(int i = 0;i<8;i++){
            if(hotColdTable[childIndex]==0){
                childIndex = 2*childIndex+2;
            }
            else if (hotColdTable[childIndex] ==1){
                childIndex = (2*childIndex)+1;
            }
        }
        if(hotColdTable[childIndex]==1){
            int temp = 2 * childIndex + 1;
            int treeIndex = temp-511;
            addressTable[treeIndex] = tag;
            update(temp);
        }
          
        else if(hotColdTable[childIndex]==0){
            int temp = 2 * childIndex + 2;
            int treeIndex = temp-511;
            addressTable[treeIndex] = tag;
            update(temp);
        }   
    }
}