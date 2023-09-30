#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

signed main(){__
    int t,n,k;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> a(n);
        vector<int> b(n);
        for(auto &c:a)cin>>c;
        for(auto &c:b)cin>>c;

        int mx1 = *max_element(a.begin(),a.end());
        int mx2 = *max_element(b.begin(),b.end());
        int mx = 0;
        for(int i = 0;i<n;i++){
            mx = max(mx,min(a[i],b[i]));
        }
        cout<<max(mx1,mx2)*mx<<endl;
    }
    return 0;
}