#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
const int maxn = 100007;
vector<lli> V(maxn);
vector<int> graph[maxn];
vector<lli> d(maxn);
vector<lli> i(maxn);

void dfs(int u,int p = -1){
    lli D = 0, I = 0;
    for(auto v:graph[u]){
        if(v != p) dfs(v, u);
        D = max(D, d[v]);
        I = max(I, i[v]);
    }
    
    lli diff = V[u] - (D - I);
    if(diff > 0) D += diff; 
    else I -= diff;
    d[u] = D;
    i[u] = I;
}
 
int main(){
    int n,u,v;
    cin>>n;
    for(int i = 0;i<n-1;i++){
        cin>>u>>v;
        graph[--u].push_back(--v);
        graph[v].push_back(u);
    }
    for(int i = 0;i<n;i++)
        cin>>V[i];

    dfs(0);
    cout<<d[0]+i[0]<<endl;
    return 0;
}