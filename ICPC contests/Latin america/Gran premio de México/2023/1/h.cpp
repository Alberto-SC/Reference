#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

const int maxn = 400007;
vector<vector<int>> trie;

vector<int> leaf(maxn);

int newNode(){
  trie.push_back(vector<int>(26,-1));
  return trie.size()-1;
}

void add(string &s){
  int cur = 0;
  for(auto c:s){
    if(trie[cur][c-'a']==-1){
      trie[cur][c-'a'] = newNode();
    }
    cur = trie[cur][c-'a'];
  }
  leaf[cur] = true;
}
string s;

int dp[maxn];

int solve(int idx,int u){
  if(idx == s.size())return 1;
  
  int &x = dp[idx];
  if(x!=-1)return x;

  int nxt1 = trie[u][s[idx]-'a'];
  int nxt2 = trie[0][s[idx]-'a'];

  int ans = 0;
  
  if(nxt1!=-1) ans +=solve(idx+1,nxt1);
  if(leaf[u] && nxt2!=-1 && nxt2!= nxt1) ans +=solve(idx+1,nxt2);

  return x = ans;
}


signed main(){__
  int m;
  cin>>m;
  newNode();
  for(int i = 0; i<m;i++){
    string t;
    cin>>t;
    add(t);
  }

  cin>>s;
  memset(dp,-1,sizeof(dp));
  cout<<solve(0,0)<<endl;
  return 0;
}