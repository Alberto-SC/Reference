#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n;
    while(t--){
        cin>>n;
        vector<int> nums(n);
        int mx = 0,g = 0;
        for(auto &c:nums)cin>>c,mx = max(c,mx),g = __gcd(c,g);
        if(((mx/g)-n)&1)cout<<"Alice"<<endl;
        else cout<<"Bob"<<endl;
        
    }
    return 0;
}  
