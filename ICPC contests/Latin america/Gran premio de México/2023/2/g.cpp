#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){
  int T = 1,n;
  cin>>n>>T;
  vector<int> in(n),out(n);

  int ans = 0;
  multiset<int> sO;
  multiset<int> sI;
  multiset<int> both;
  for(int i = 0;i<n;i++)
    both.insert(1),sO.insert(0),sI.insert(0);

  while(T--){
    int u,v;
    cin>>u>>v;
    u--,v--;
    ans+=in[u]+out[v]+(u==v);


    sI.erase(sI.find(in[v]));
    in[v]++;
    sI.insert(in[v]);

    sO.erase(sO.find(out[u]));
    out[u]++;
    sO.insert(out[u]);

    both.insert(in[u]+out[u]+1);
    both.insert(in[v]+out[v]+1);


    int mx1 = *sI.rbegin();
    int mx2 = *sO.rbegin();
    int mx3 = *both.rbegin();
    int ans2 = max(mx3,mx1+mx2);
    cout<<ans<<" "<<ans2<<endl;
  }
  
}