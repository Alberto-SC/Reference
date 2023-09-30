#include <bits/stdc++.h>
#define int long long 
#define endl '\n'
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
using namespace std;
 
signed main() {__
    int T,n,k,a,b;
    cin>>T;
    while(T--){
      cin>>n>>k;
      int ans = 0;
      vector<int> v;
      for(int i = 0;i<n;i++){
        cin>>a>>b;
        if(a>b)ans+=3;
        else if(a==b){
          if(k){
            ans+=3;
            k--;
          }
          else{
            ans++;
          }
        }
        else{
          v.push_back(b-a);
        }
      }

      sort(v.begin(),v.end());
      for(int i = 0;i<v.size();i++){
        if(v[i]+1<=k){
          ans+=3;
          k-=v[i]+1;
        }
        else if(v[i]<=k){
          ans++;
          k-=v[i];
        }
      }
      cout<<ans<<endl;
    }
    return 0;
}


