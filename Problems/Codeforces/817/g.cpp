#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define endl '\n'
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);


signed main(){
  int T = 1,n;
  cin>>T;
  while(T--){
    cin>>n;
    int pr = n/2;
    int im = (n+1)/2;
    vector<int> ans(n); 
    int pw = 0,x = 1;
    while(x<n){
      x*=2;
      pw++;
    }
    x*=2;
    if(pr%2==0){
      int key = 1;
      for(int i = 0;i<n;i+=2)
        ans[i] = key++;
      key = 1;
      for(int i = 1;i<n;i+=2)
        ans[i] = (key++)+x;
      if(im&1)
        ans[n-1] = 0;
    }
    else{
      int key = 1;
      for(int i = 1;i<n;i+=2)
        ans[i] = key++;
      key =1;
      for(int i = 0;i<n;i+=2)
        ans[i] = (key++)+x;
      if(im&1){
        ans[n-1] = (1<<30);
        ans[n-2] = (1<<30)+(1<<29);
        ans[n-3] = (1<<29);
        ans[n-4] = x;
      }
      else
        ans[n-1] = x;
    }
    for(auto c:ans)cout<<c<<" ";
    cout<<endl;
    int a = 0,b = 0;
    for(int i = 0;i<n;i++){
      if(i&1)a^=ans[i];
      else b^=ans[i];
    }
  }
}

