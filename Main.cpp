#include<iostream>
#include<fstream>
#include<sstream>

#include"DirectCache.h"
#include"DirectCache.h"
#include "SetAssociateCache.h"
#include "SetAssociateCache.h"
#include "FullAssociateCache.h"
#include "FullAssociateCache.h"
#include "Prefetch.h"
#include "Prefetch.h"
#include "SetAssociateNot.h"
#include "SetAssociateNot.h"
#include "HotCold.h"
#include "HotCold.h"
using namespace std;



int main(int argc, char*argv[]){
    //Check inputs
    if(argc != 3){
        cerr<<"Input error, correct input: ./cache-sim <input.txt> <output.txt>"<<endl;
        exit(1);
    }
    unsigned long long addr = 0;
    string line;
    string behavior;
    string tempLine;
    string tempBehavior;
    unsigned long long tempAddr = 0;

    ofstream outfile;
    outfile.open(argv[2]);
    ifstream infile(argv[1]);

    DirectCache d1(1024);
    DirectCache d2((4*1024));
    DirectCache d3((16*1024));
    DirectCache d4((32*1024));
    
    SetAssociateCache sac1((16*1024));
    SetAssociateCache sac2((16*1024));
    SetAssociateCache sac3((16*1024));
    SetAssociateCache sac4((16*1024));

    
    SetAssociateNot san1((16*1024));
    SetAssociateNot san2((16*1024));
    SetAssociateNot san3((16*1024));
    SetAssociateNot san4((16*1024));

    
    FullAssociateCache fac((16*1024));

    Prefetch pf1 ((16*1024));
    Prefetch pf2 ((16*1024));
    Prefetch pf3 ((16*1024));
    Prefetch pf4 ((16*1024));

    Prefetch pfn1 ((16*1024));
    Prefetch pfn2 ((16*1024));
    Prefetch pfn3 ((16*1024));
    Prefetch pfn4 ((16*1024));

    HotCold hc((16*1024));

    int count= 0;
    while(getline(infile,line)){

        
        stringstream s(line);
        s >>behavior>>std::hex >>addr;

        //Directcache
        d1.MapAddr(addr);
        d2.MapAddr(addr);
        d3.MapAddr(addr);
        d4.MapAddr(addr);

        sac1.MapAddr(addr,2);
        sac2.MapAddr(addr,4);
        sac3.MapAddr(addr,8);
        sac4.MapAddr(addr,16);

        fac.MapAddr(addr);

        san1.MapAddr(addr,2,behavior);
        san2.MapAddr(addr,4,behavior);
        san3.MapAddr(addr,8,behavior);
        san4.MapAddr(addr,16,behavior);
        
        pf1.MapAddr(addr,2,0);
        pf2.MapAddr(addr,4,0);
        pf3.MapAddr(addr,8,0);
        pf4.MapAddr(addr,16,0);
        
        pfn1.MapAddr(addr,2,1);
        pfn2.MapAddr(addr,4,1);
        pfn3.MapAddr(addr,8,1);
        pfn4.MapAddr(addr,16,1);

        hc.MapAddr(addr);
    
    }
    //direct map cache output
    outfile<<d1.hit<<","<<d1.totalHit<<";";
    outfile<<d2.hit<<","<<d2.totalHit<<";";
    outfile<<d3.hit<<","<<d3.totalHit<<";";
    outfile<<d4.hit<<","<<d4.totalHit<<";";
    outfile<<endl;

    //set associate cache output
    outfile<<sac1.hit<<","<<sac1.totalHit<<";";
    outfile<<sac2.hit<<","<<sac2.totalHit<<";";
    outfile<<sac3.hit<<","<<sac3.totalHit<<";";
    outfile<<sac4.hit<<","<<sac4.totalHit<<";";
    outfile<<endl;
    
    // Full Associate LRU output
    outfile<<fac.hit<<","<<fac.totalHit<<";";
    outfile<<endl;

    //Full Assocaite HC output
    outfile<<hc.hit<<","<<hc.totalHit<<";";
    outfile<<endl;

    //Set associate with not allocation on write miss
    outfile<<san1.hit<<","<<san1.totalHit<<";";
    outfile<<san2.hit<<","<<san2.totalHit<<";";
    outfile<<san3.hit<<","<<san3.totalHit<<";";
    outfile<<san4.hit<<","<<san4.totalHit<<";";
    outfile<<endl;

    outfile<<pf1.hit<<","<<pf1.totalHit<<";";
    outfile<<pf2.hit<<","<<pf2.totalHit<<";";
    outfile<<pf3.hit<<","<<pf3.totalHit<<";";
    outfile<<pf4.hit<<","<<pf4.totalHit<<";";
    outfile<<endl;

    outfile<<pfn1.hit<<","<<pfn1.totalHit<<";";
    outfile<<pfn2.hit<<","<<pfn2.totalHit<<";";
    outfile<<pfn3.hit<<","<<pfn3.totalHit<<";";
    outfile<<pfn4.hit<<","<<pfn4.totalHit<<";";
    outfile<<endl;


    return 0;
}