#include <bits/stdc++.h>
using namespace std;
vector<int> p;
int find(int i){return p[i] == i?i:p[i] = find(p[i]);}
int main(){
    int n,m,l,r,x;
    cin>>n>>m;
    vector<int> ans(n+1,-1);
    p.resize(n+1);
    for(int i = 0;i<=n;i++)p[i] = i;
    for(int i = 0;i<m;i++){
        cin>>l>>r>>x;
        l--,r--,x--;
        for(int j = find(l);j<x;j = find(j+1))ans[j] = p[j] = x;
        for(int j = find(x+1);j<=r;j = find(j+1))ans[j] = x,p[j] = find(r+1);
    }
    for(int i = 0;i<n;i++)cout<<ans[i]+1<<" ";
    return cout<<endl,0;
}