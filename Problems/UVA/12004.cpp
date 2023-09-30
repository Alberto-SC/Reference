#include <bits/stdc++.h>
#define int long long
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
using namespace std;

int fact(int n){
  if(n ==1)return 1;
  return n*fact(n-1);
}

signed main(){__
  int t,n;
  cin>>t;
  cout<<fixed<<setprecision(3);
  vector<int> pre(1000007);
  pre[1] = 0;
  pre[2] = 0;
  pre[3] = 1;
  pre[4] = 3;
  pre[5] = 5;
  pre[6] = 7;
  int sum = 3;
  for(int i = 7;i<=100000;i++){
    pre[i] = pre[i-1]+sum;
    if((i-7)%4==0)sum++;
    if((i-7)%4==3)sum++;
  }
  int id = 1;
  while(t--){
    cin>>n;
    cout<<"Case "<<id<<": ";
    if(n%4==2 || n%4==3){
      cout<<((pre[n]*2)+1)<<"/2"<<endl;
    }
    else cout<<pre[n]<<endl;
    id++;
  }
  return 0;
}

