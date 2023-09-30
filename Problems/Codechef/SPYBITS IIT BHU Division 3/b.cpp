#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> a(n);
        vector<int> b(n);
        for(auto &c:a)cin>>c;
        for(auto &c:b)cin>>c;
        int ans = 0;
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        for(int i = 0;i<n;i++)
            ans = max(ans,a[i]+b[(n-i)-1]);
        cout<<ans<<endl;
    }
    return 0;
}  
