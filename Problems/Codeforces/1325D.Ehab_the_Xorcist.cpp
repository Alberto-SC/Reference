#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main(){
    lli n,u,v;
    cin>>u>>v;
    if(u>v || (u&1) != (v&1))return cout<<-1<<endl,0;
    lli x = (v-u)/2;
    if(v==u){
        if(!v)
            return cout<<0<<endl,0;
        else 
            return cout<<1<<endl<<u<<endl,0;
    }
    if(x&u){
        cout<<3<<endl;
        cout<<u<<" "<<x<<" "<<x<<endl;
    }
    else{
        cout<<2<<endl;
        cout<<u+x<<" "<<x<<endl;
    }


    return 0;
}