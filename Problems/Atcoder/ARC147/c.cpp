#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n;
    while(T--){
        cin>>n;
        vector<int> l(n),r(n);

        for(int i = 0;i<n;i++){
            cin>>l[i]>>r[i];
        }

        sort(l.rbegin(),l.rend());
        sort(r.begin(),r.end());
        int ans = 0;
        for(int i = 0;i<n;i++)
            ans += max(0ll,l[i]-r[i])* (n-((2*i)+1));
        cout<<ans<<endl;
    }
    return 0;
}