#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

signed main(){__
    int y,m;
    cin>>y>>m;
    int ay = 0,am = 0;
    if(y<1){
        am+=m*15;
        ay = 0;
    }
    else if(y<2){
        ay =15 ;
        am+= m*9;
    }
    else {
        ay = 15+9 +(y-2)*4;
        am+=m*4;
    }
    int x=am/12;
    am-=x*12;
    cout<<ay+x<<" "<<am<<endl;
}   