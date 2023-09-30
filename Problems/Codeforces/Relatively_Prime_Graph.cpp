#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>> graph;
    int cont = 0;
    if(m<n-1)return cout<<"Impossible"<<endl,0;
    for(int i = 1;i<=n;i++){
        if(cont == m)break;
        for(int j = i+1;j<=n;j++){
            if(__gcd(i,j)== 1)graph.push_back({i,j}),cont++;
            if(cont == m)break;
        }
    }
    if(cont != m)return cout<<"Impossible"<<endl,0;
    cout<<"Possible"<<endl;
    for(auto c:graph)cout<<c.first<<" "<<c.second<<endl;
    return 0;
}