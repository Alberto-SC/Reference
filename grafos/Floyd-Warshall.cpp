#include <bits/stdc++.h>
using namespace std;

int n;

void Floyd(){
    for (lli k = 0; k < n; ++k) {
        for (lli i = 0; i < n; ++i) {
            for (lli j = 0; j < n; ++j) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]); 
            }
        }
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    for(int i = 0;i<m;i++){
        cin>>u>>v;
        u--,v--;
        dist[u][v] = 1;
        dist[v][u] = 1;
    }
    Floyd();
    return 0;
}
