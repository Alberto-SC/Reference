#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ld long double
signed main(){__
	int t= 1,n,k;
    while(t--){
        cin>>n>>k;
        vector<int> nums(k);
        int sum = 0;
        for(auto &c:nums)cin>>c,sum+=c;
        int mn = sum+ (n-k)*-3;
        int mx = sum+ (n-k)*3;
        ld mxd = mx/(n*1.0);
        ld mnd = mn/(n*1.0);
        cout<<fixed<<setprecision(10);
        cout<<mnd<<" "<<mxd<<endl;
    }
    return 0;
}  
