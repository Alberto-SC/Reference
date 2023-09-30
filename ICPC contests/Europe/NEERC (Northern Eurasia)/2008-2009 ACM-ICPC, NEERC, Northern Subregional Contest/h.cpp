#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
int main(){
    freopen("holes.in","r",stdin);
    freopen("holes.out","w",stdout);
    int n;
    cin>>n;
    if(n == 0)return cout<<1<<endl,0;
    if(n == 1)return cout<<0<<endl,0;
    if(n&1)cout<<4;
    for(int i =0;i< n/2;i++)cout<<"8";
    cout<<endl;
    return 0;
}