#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
  int T = 1,n,k,m;
  cin>>T;
  while(T--){
    cin>>n>>m>>k;

    vector<int> id(k);
    for(auto &c:id)cin>>c,c--;
    vector<int> D(k);
    for(auto &c:D)cin>>c;

    vector<vector<int>> graph(n);

    for(int i = 0;i<m;i++){
      int u,v;
      cin>>u>>v;
      u--,v--;
      graph[u].push_back(v);
      graph[v].push_back(u);
    }

    set<pair<int,int>,greater<pair<int,int>>> st;

    vector<int> d(n,-1);
    for(int i = 0;i<k;i++){
      st.insert({D[i]-1,id[i]});
      d[id[i]] = D[i]-1;
    }

    while(st.size()){
      int u = st.begin()->second;
      int cD = st.begin()->first;
      // cout<<u<<" "<<cD<<endl;
      st.erase(st.begin());
      if(cD ==0)
        continue;

      for(auto v:graph[u]){
        if(d[v]<d[u]-1){
          d[v] = d[u]-1;
          st.insert({d[v],v});
        }
      }
    }

    bool flag = true;
    for(auto c:d){
      // cout<<c<<" ";
      if(c==-1)flag = false;
    }
    // cout<<endl;
    cout<<(flag?"YES":"NO")<<endl;

  }
  return 0;
}