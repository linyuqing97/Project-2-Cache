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



    while(getline(infile,line)){
        
        /*addr = tempAddr;
        behavior = tempBehavior;
        */
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
        
        
    }
   cout<<sac1.hit<<endl;

    cout<<d1.hit<<" "<<d1.totalHit<<endl;
    cout<<sac4.hit<<" "<<sac1.totalHit<<endl;

   cout<<"Not allocate misses "<< san4.hit<<" "<<san4.totalHit<<endl;
    cout<<pf1.hit<<endl;

  
    return 0;

}