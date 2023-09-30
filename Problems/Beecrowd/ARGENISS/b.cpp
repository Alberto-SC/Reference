#include <bits/stdc++.h>
#define int long long 
#define endl '\n'
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
using namespace std;
 
signed main() {__
    int n,k,x,d;
    cin>>n>>k;
    vector<pair<int,int>> v;
    vector<int> t;
    for(int i = 0;i<k;i++){
      cin>>x>>d;
      v.push_back({x,d});
      t.push_back(x);
    }
    vector<int> mp(n+1);
    for(int i = 0;i<k;i++){
      vector<int> m;
      for(int j = 0;j<k;j++){
        if(v[j].first==t[i]){
          m.push_back(n);
        }
        else if(v[j].second==-1){
          if(v[j].first>t[i])
            m.push_back(v[j].first-t[i]);
          else 
            m.push_back(n-(t[i]-v[j].first));
        }
        else{
          if(v[j].first>t[i])
            m.push_back(n-(v[j].first-t[i]));
          else 
            m.push_back(t[i]-v[j].first);
        }
      }
      sort(m.begin(),m.end());
      for(int i = 0;i<m.size();i++){
        if(i && m[i]==m[i-1])continue;
        mp[m[i]]++;
      }
    } 
    for(int i = 1;i<=n;i++){
      if(mp[i]==k){
        cout<<i<<endl;
        break;
      }
    }
}

