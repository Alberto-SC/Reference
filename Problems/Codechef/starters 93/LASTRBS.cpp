#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

string s;
string res;
vector<vector<vector<int>>> dp;
int n;

bool solve(int idx,int diff,int last,string &Sans){
  if(diff<0)return 0;
  if(idx == n){
    if(diff == 0){
      res = Sans;
      return 1;
    }
    return 0;
  }

  int &x = dp[idx][diff][last];
  if(x !=-1)return x;
  

  bool ans = false;
  if(idx == 0){
    Sans.push_back('(');
    if(idx == 0)  ans |= solve(idx+1,diff+1,0,Sans);
    Sans.pop_back();
  }
  else{
    if(s[idx]== s[idx-1]){
      if(last == 0){
        Sans.push_back('(');
        ans |= solve(idx+1,diff+1,0,Sans);
        Sans.pop_back();
      } 
      else{
        Sans.push_back(')');
        ans |= solve(idx+1,diff-1,1,Sans);
        Sans.pop_back();
      } 
    }
    else{
      Sans.push_back('(');
      ans |= solve(idx+1,diff+1,0,Sans);
      Sans.pop_back();
      Sans.push_back(')');
      ans |= solve(idx+1,diff-1,1,Sans);
      Sans.pop_back();
    }
  }
  return x = ans;
}

signed main(){__
  int T = 1;
  cin>>T;
  while(T--){
    cin>>n;                                                           
    cin>>s;
    dp.assign(n,vector<vector<int>>(n,vector<int>(2,-1)));
    string t = "";
    if(solve(0,0,0,t))cout<<"YES"<<endl<<res<<endl;
    else cout<<"NO"<<endl;
  }
  return 0;
} 