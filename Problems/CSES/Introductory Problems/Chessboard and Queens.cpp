#include <bits/stdc++.h>
using namespace std;

int n = 8;
char M[8][8];
int OK = (1<<n)-1;
int solve(int mask,int maskl,int maskr,int idx = 0){
  if(mask ==OK)return 1;
  int ans = 0;
  int valid = OK& (~(mask|maskl|maskr));
  for(int i = 0;i<n;i++){
    if((valid>>i)&1 && M[idx][i]=='.'){
      int pos = 1<<i;
      ans+=solve(mask|pos,(maskl|pos)<<1,(maskr|pos)>>1,idx+1);
    }
  }
  return ans;
    
}

int main(){
  for(int i = 0;i<n;i++){
    for(int j = 0;j<n;j++){
      cin>>M[i][j];
    }
  }
  cout<<solve(0,0,0)<<endl;
  return 0;
}
