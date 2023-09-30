#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n;
    cin>>T;
    while(T--){
        cin>>n;
        string s;
        cin>>s;
        int ans = 2;
        int x = 1;
        for(int i = 1;i<n;i++){
          if(s[i-1]==s[i])
            x++;
          else {
            ans = max(ans,x+1);
            x = 1;
          }
        }
        ans = max(ans,x+1);
        cout<<ans<<endl;
    }
    return 0;
}