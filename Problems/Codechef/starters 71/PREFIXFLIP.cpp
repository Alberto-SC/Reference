#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n,k;
    cin>>T;
    while(T--){
        cin>>n>>k;
        string s;
        cin>>s;
        vector<int> pref(n);
        for(int i = 1;i<n;i++){
            pref[i] = pref[i-1]+(s[i]!=s[i-1]);
        }
        int ans = n+1;
        for(int i = 0;i<=n-k;i++){
            int ac = pref[i+k-1]-pref[i];
            if(s[(i+k)-1]=='0')ans = min(ans,ac+1);
            else ans = min(ans,ac);
        }
        cout<<ans<<endl;
    }
    return 0;
}