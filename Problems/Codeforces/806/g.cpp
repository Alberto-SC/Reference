#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n,k;
    cin>>t;
    while(t--){
        cin>>n>>k;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        
        int ans = 0;
        for(int i = 0;i<min(n,35ll);i++){
            ans+=nums[i]/(1ll<<(i+1));
        }
        // cout<<ans<<endl;
        int sum = 0;
        for(int i = 0 ;i<n;i++){
            sum+=nums[i];
            int x = sum-(k*(i+1));
            int y = 0;
            for(int j = i+1;j<min(n,i+1+35);j++){
                y+=nums[j]/(1ll<<(j-i));
            }
            ans = max(ans,x+y);
        }
        cout<<ans<<endl;
    }
    return 0;
}  
