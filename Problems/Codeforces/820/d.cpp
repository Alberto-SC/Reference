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
        vector<int> a(n);
        vector<int> b(n);
        for(auto &c:a)cin>>c;
        for(auto &c:b)cin>>c;
        vector<int> v(n);
        for(int i = 0;i<n;i++){
            v[i] = b[i]-a[i];
        }
        int l = 0,r = n-1;
        sort(v.begin(),v.end());
        int ans = 0;
        while(l<r){
            while(l<r && v[l]+v[r]<0){
                l++;
            }
            if(l>=r)break;
            ans++;
            l++;
            r--;
        }
        cout<<ans<<endl;
    }
    return 0;
}