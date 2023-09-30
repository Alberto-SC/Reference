#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m,p,i,j;
    cin>>n>>m>>p;
    vector<int>ca(n);
    vector<int>cb(m);
    for(auto &c:ca)cin>>c;
    for(auto &c:cb)cin>>c;
    for(i = 0;i<n;i++)if(ca[i]%p== 0)break;
    for(j = 0;j<m;j++)if(cb[j]%p== 0)break;
    cout<<i+j<<endl;
    return 0;
}