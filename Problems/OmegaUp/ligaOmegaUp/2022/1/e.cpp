#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

const int inf = 1e9;
signed main(){__
	int t= 1,n;
    while(t--){
        cin>>n;
        vector<int> nums(n);
        int s = 0;
        for(auto &c:nums)cin>>c,s+=c;
        if(s&1)return cout<<s<<endl,0;
        int mn = inf;
        for(int i = 0;i<n;i++){
            if(nums[i]&1)mn = min(mn,nums[i]);
        }
        if(mn ==inf)cout<<0<<endl;
        else cout<<s-mn<<endl;
    }
    return 0;
}  
