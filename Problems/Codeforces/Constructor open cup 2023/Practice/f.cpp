#include <bits/stdc++.h>
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

using namespace std;

signed main(){__
    int T,n;
    cin>>T;
    while(T--){
        string s;
        cin>>s;
        int n = s.size();
        vector<int> pref(n);
        
        pref[0] = s[0]=='1';

        for(int i = 1;i<n;i++)
            pref[i] = pref[i-1] + (s[i]=='1');
         
        int ans = 1e9;
        int k = pref[n-1];
        if(k == 0){
            cout<<0<<endl;
            continue;
        }
        for(int i = 0;i<=n-k;i++){
            int x = pref[(i+k)-1]-(i?pref[i-1]:0);
            ans = min(ans,k-x);
        }
        cout<<ans<<endl;
    }
    return 0;
}

