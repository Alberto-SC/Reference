#include <bits/stdc++.h>
using namespace std;
const int N = 101;

/*
    Solve lineal algrebraic ecuations for Z2

*/
int gauss (vector <bitset<N>> a, int n, int m, bitset<N> & ans) {
    vector<int> where (m, -1);
    for (int col=0, row=0; col<m && row<n; ++col) {
        for (int i=row; i<n; ++i)
            if (a[i][col]) {
                swap (a[i], a[row]);
                break;
            }
        if (! a[row][col])
            continue;
        where[col] = row;
 
        for (int i=0; i<n; ++i)
            if (i != row && a[i][col])
                a[i] ^= a[row];
        ++row;
    }
    for (int i=0; i<m; ++i)
        if (where[i] != -1)
            ans[i] = a[where[i]][m];
    for (int i=0; i<n; ++i) {
        int sum = 0;
        for (int j=0; j<m; ++j)
            sum += ans[j] * a[i][j];
        if (sum - a[i][m])
            return 0;
    }
 
    for (int i=0; i<m; ++i)
        if (where[i] == -1)
            return 1e9;
    return 1;
}
vector<int> graph[107];
int main(){
    int n,m,u,v;
    cin>>n>>m;
    for(int i = 0;i<m;i++){
        cin>>u>>v;
        u--,v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    vector<bitset<N>> SLAE(n);
    for(int i = 0;i<n;i++){
        for(auto c:graph[i])
            SLAE[i].set(c);
        if(graph[i].size()&1)
            SLAE[i].set(i);
        else 
            SLAE[i].set(n);
    }
    bitset<N>ans(0);
    if(gauss(SLAE,n,n,ans)) 
        cout<<"Y"<<endl;
    else cout<<"N"<<endl;
    return 0;
}