#define _GLIBCXX_DEBUG 1
#define _GLIBCXX_DEBUG_PEDANTIC 1
#define _FORTIFY_SOURCE 2
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

const maxn = 100;
vector<pair<int,int>> graph[maxn];
void add_edge(int u,int v,int p){
    graph[v].push_back({u,p});

}

int cont = 0;
double dfs(int u,double &pb,int deep = 0){
    double aux = 1.0;
    for(auto v:graph[u]){
        if(deep == 0)
            pb*=v.y;
        else pb*=1-(v.y);
        dfs(v,pb,deep+1);
    }   
}


int main(){
    int n,m,u,v,p;
    cin>>n>>m;
    for(int i = 0;i<m;i++){
        cin>>u>>v>>p;
        add_edge(u,v,p);
    }

    vector<int> ans(n,1.0);
    for(int i = 1;i<=n;i++){
        cont = 0;
         dfs(i,ans[i-1]);
    }
    for(auto c:ans)cout<<1-c<<endl;
    return 0;
}