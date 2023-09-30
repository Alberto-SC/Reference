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
        vector<int> nums(n);
        int s = (1ll<<40)-1;
        for(auto &c:nums)cin>>c,s&=c;
        cout<<s<<endl;
    }
    return 0;
}  
