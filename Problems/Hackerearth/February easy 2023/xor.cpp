#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n,x;
    cin>>T;
    while(T--){
        cin>>n;
        map<int,int> mp;
        int ans = 0;
        for(int i = 1;i<=n;i++){
            cin>>x;
            ans+=mp[x^i];
            mp[x^i]++;
        }
        cout<<ans<<endl;
    }
    return 0;
}