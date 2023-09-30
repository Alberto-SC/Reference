#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);  
    string typeT,typeN;
    int nT,nN;
    while(cin>>typeT>>nT){
        cin>>typeN>>nN;
        if(typeN == typeT)cout<<"Draw\n";
        if(typeT =="Cruisers"){
            if(typeN =="Battleships"){
                if(nN<2*nT)cout<<"Tobby\n";
                else cout<<"Naebbirac\n";
            }
            else if(typeN == "Destroyers"){
                if(nT>=nN*2)cout<<"Tobby\n";
                else cout<<"Naebbirac\n";
            }
        }
        else if(typeT =="Battleships"){
            if(typeN =="Destroyers"){
                if(nN<2*nT)cout<<"Tobby\n";
                else cout<<"Naebbirac\n";
            }
            else if(typeN == "Cruisers"){
                if(nT>=nN*2)cout<<"Tobby\n";
                else cout<<"Naebbirac\n";
            }
        }
        else if(typeT =="Destroyers"){
            if(typeN =="Cruisers"){
                if(nN<2*nT)cout<<"Tobby\n";
                else cout<<"Naebbirac\n";
            }
            else if(typeN == "Battleships"){
                if(nT>=nN*2)cout<<"Tobby\n";
                else cout<<"Naebbirac\n";
            }
        }
    }
    return 0;
}