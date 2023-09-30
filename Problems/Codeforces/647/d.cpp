#include <bits/stdc++.h>
using namespace std;
#define endl '\n'  
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
const int maxn = 500007;
vector<int> graph[maxn];
void add_edge(int u,int v){
    graph[u].push_back(v);
    graph[v].push_back(u);
}
vector<int> a;
int main(){__
    lli n,m,u,v;
    cin>>n>>m;
    for(int i = 0;i<m;i++){
        cin>>u>>v;
        u--,v--;
        add_edge(u,v);
    }
    int root = 0,mx = -1;
    a.resize(n);
    for(int i = 0;i<n;i++){
        cin>>a[i];
        if(a[i]>mx)root = i;
    }
    for(int i = 0;i<n;i++){
        set<int> s;
        for(auto v:graph[i]){
            if(a[v]== a[i])return cout<<-1<<endl,0;
            if(a[v]<a[i])s.insert(a[v]);
        }
        if(s.size()!= a[i]-1)return cout<<-1<<endl,0;
    }
    vector<pair<int,int>> b(n);
    for(int i = 0;i<n;i++)
        b[i] = {a[i],i};

    sort(b.begin(),b.end());

    for(int i = 0;i<n;i++)
        cout<<b[i].second+1<<" ";
    cout<<endl;
    return 0;
}