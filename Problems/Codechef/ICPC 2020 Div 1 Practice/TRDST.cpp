#include <bits/stdc++.h>
using namespace std;
const int maxn = 100007;
vector<int> graph[maxn];
int main(){
    int n;
    cin>>n;
    vector<int> k(n);
    for(auto &c:k)cin>>c;
    for(int i = 0;i<n-1;i++){
        cin>>u>>v;
        u--,v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }


    return 0;
}