#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main(){
    lli q,x,y,k;
    cin>>q;
    while(q--){
        cin>>x>>y>>k;
        if(x<y)swap(x,y);
        if(x%2 != y%2)k-=1,x-=1;
        else if(x%2 != k%2)k-=2,x-=1,y-=1;
        k<x?cout<<-1<<endl:cout<<k<<endl;
    }
    return 0;
}