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
        int ans = 1;
        vector<int> mp(26);
        for(int i = 0;i<n;i++){
            mp[s[i]-'a']++;
            ans = max(ans,(mp[s[i]-'a']+(k-1))/k);
        }
        cout<<ans<<endl;
    }
    return 0;
}