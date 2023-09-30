#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

bool check(int x,int k,int n,int m){
  int cont = 0;
  for(int i= 1;i<=n;i++){
    cont+=min(m,x/i);
  }
  return cont>=k;
}

signed main(){
  int n,m,k;
  cin>>n>>m>>k;
  int l = 0,r = n*m+1;
  while(l+1<r){
    int mid = (l+r)>>1;
    if(check(mid,k,n,m))r = mid;
    else l = mid;
  }
  cout<<r<<endl;
  return 0;
}
 


