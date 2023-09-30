#include <bits/stdc++.h>
using namespace std;
int main(){
    int mod,h,m;
    char a;
    cin>>mod>>h>>a>>m;
    if(mod == 24){
        while(h>23)
            h-=10;
        if(h<10)
            cout<<0;
        cout<<h;
    }
    
    if(mod == 12){
        if(h == 0)h++;
        while(h >12)
            h-=10;
        if(h<10)cout<<0;
        cout<<h;
    }
    cout<<":";
    while(m>59)m-=10;
    if(m<10)cout<<0;
    cout<<m;
    return 0;
}