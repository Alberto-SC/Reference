#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;
const int maxn = 3007;
vector<lli> graph[maxn];
lli g[maxn][maxn];
int main(){
    int n,m,u,v;
    cin>>n>>m;
    for(int i = 0;i<m;i++){
        cin>>u>>v;
        u--,v--;
        graph[u].push_back(v);
        g[u][v] = 1;
    }

    lli ans = 0;
    for(int a = 0;a<n;a++){
        for(int c = 0;c<n;c++){
            if(c == a)continue;
            lli x = 0;
            for(int i =  0;i<graph[a].size();i++){
                if(graph[a][i] != a && graph[a][i]!= c && g[graph[a][i]][c])x++;
            }
            ans+=(x*(x-1))/2;
        }
    }
    cout<<ans<<endl;
    return 0;
}