#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define endl '\n'
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);

signed main(){__
  int T = 1,n;
  cin>>T;
  while(T--){
    cin>>n;
    string s;
    cin>>s;
    priority_queue<int> q;
    int ans = 0;
    for(int i = 0;i<n;i++){
      if(s[i]== 'L'){
        int x = i;
        int y = (n-1)-i;
        if(y>x){
          q.push(y);
        }
        ans+=x;
      } 
      else{
        int x = (n-1)-i;
        int y = i;
        if(y>x)
          q.push(y);
        ans+=x;
      }
    } 
   

    for(int i = 0;i<n;i++){
      if(q.empty()){
        cout<<ans<<" ";
        continue;
      }
      int mx = q.top();
      q.pop();
      ans+= mx;
      ans-=(n-1)-mx;
      cout<<ans<<" ";
    }

    cout<<endl;


  }
}

