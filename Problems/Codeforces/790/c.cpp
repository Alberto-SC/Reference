#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

signed main(){__
  int t,n,m;
  cin>>t;
  while(t--){
    cin>>n>>m;
    vector<string> S(n);
    for(auto &c:S)cin>>c;
    int mn = 1e9;
    for(int i =0;i<n;i++){
        for(int j = i+1;j<n;j++){
            int dist = 0;
            for(int k = 0;k<m;k++){
                if(S[i][k]<S[j][k])
                    dist+=S[j][k]-S[i][k];
                else 
                    dist+=S[i][k]-S[j][k];
            }
            mn = min(mn,dist);
        }
    }
    cout<<mn<<endl;
  }
  return 0;
}
