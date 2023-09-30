#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

const int mod = 1e9+7;
signed main(){__
	int t= 1,n;
    while(t--){  
        cin>>n;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        int x = 0;
        int cont = 0;
        int ans = 0;
        int ones = 0;
        bool first = false;
        for(int i = 0;i<n;i++){
            if(nums[i]==3)(ans+=x)%=mod;
            if(nums[i]==1)ones++;
            if(nums[i]==2){
                x*=2;
                x+=ones;
                x%=mod;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}  
