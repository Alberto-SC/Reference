
#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define endl '\n'
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);

vector<vector<int>> getPrefix(vector<vector<int>> M){
  int n = M.size();
  int m = n;
  vector<vector<int>> P(n,vector<int>(m));
  for(int i = 0;i<m;i++){
    P[0][i] = M[0][i];
  }
  for(int i = 0;i<n;i++){
    P[i][0] = M[i][0];
  }

  for(int i = 1;i<n;i++){
    for(int j = 1;j<m;j++){
      P[i][j] =(M[i][j]+ P[i][j-1]+P[i-1][j])-P[i-1][j-1];
    }
  }
  return P;
}

int query(int a,int b,int c,int d,vector<vector<int>> &P){
  int L = 0;
  int U = 0;
  int D = 0;
  if(b-1>=0)L = P[c][b-1];
  if(a-1>=0) U = P[a-1][d];
  if(a-1 && b-1)D = P[a-1][b-1];
  return P[c][d]-L-U+D;
}

void print(vector<vector<int>> M){
  for(auto c:M){
    for(auto d:c){
      cout<<d<<" ";
    }
    cout<<endl;
  }
}

signed main(){__
  int T = 1,n,q,h,w,h1,w1,h2,w2;
  cin>>T;
  while(T--){
    cin>>n>>q;
    vector<vector<int>> M(1007,vector<int>(1007));
    for(int i = 0;i<n;i++){
      cin>>h>>w;
      M[h][w] += h*w;
    }
    vector<vector<int>> prefix = getPrefix(M);  
    for(int i = 0;i<q;i++){
      cin>>h1>>w1>>h2>>w2;
      if(h1 == h2 || w1 == w2){
        cout<<0<<endl;
        continue;
      } 
      cout<<query(h1+1,w1+1,h2-1,w2-1,prefix)<<endl;
    }
    

  }
}

