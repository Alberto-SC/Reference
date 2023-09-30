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
        for(auto &c:nums)cin>>c;
        int s = 0;
        int mn = 1e12;
        for(int i = 0;i<n;i++){
            s+=nums[i];
            mn = min(s,mn);
        }
        if(mn>0)return cout<<0<<endl,0;
        else return cout<<abs(mn)<<endl,0;
    }
    return 0;
}  
