#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

void print(vector<pair<char,int>> &v,int l,int r){
  for(int i = l;i<r;i++){
    for(int j = 0;j<v[i].second;j++){
      cout<<v[i].first;
    }
  }
  cout<<endl;
}

signed main(){
  int T = 1,n,k;
  cin>>n>>k; 

  string s;
  cin>>s;
  vector<pair<char,int>> v;

  for(int i = 0;i<n;){
    int j = i;
    while(j<n && s[i]== s[j]){
      j++;
    }
    v.push_back({s[i],j-i});
    i = j;
  }

  if(v.size()==1){
    cout<<-1<<endl;
    return 0;
  }

  if(v[0].first == v.back().first){
    v[0].second+=v.back().second;
    v.pop_back();
  }
  
  int N = v.size();
  for(int i = 0;i<N;i++)v.push_back(v[i]);

  int ans = 0;

  map<char,int> mp;
  // cout<<endl;

  int l = 0,r = 0;
  int bl = -1,br = -1;
  int chars = 0;
  while(l<v.size()){
    if(r<l)r = l;
    
    while(r<v.size()){
      if(r-l==N)break;
      if(mp[v[r].first]+v[r].second>k)break;
      mp[v[r].first]+=v[r].second;
      chars+=v[r].second;
      r++;
    }
    if(chars>ans){
      bl = l;
      br = r;
      // print(v,l,r);
      ans = chars;
    }
    if(l<r){
      mp[v[l].first]-=v[l].second;
      chars-=v[l].second;
    }
    l++;
  }
  if(ans==0){
    cout<<-1<<endl;
    return 0;
  }

  cout<<ans<<endl;
  print(v,bl,br);
  return 0;
}