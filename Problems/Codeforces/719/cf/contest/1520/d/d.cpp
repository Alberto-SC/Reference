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
        map<int,int> mp;
        for(auto &c:nums)cin>>c;
        int ans = 0;
        for(int i = 1;i<=n;i++){
            int x = nums[i-1]-i;
            ans+=mp[x];
            mp[-i+nums[i-1]]++;
        }
        cout<<ans<<endl;
    }
    return 0;
}  
