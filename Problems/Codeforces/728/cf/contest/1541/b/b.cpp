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
        for(auto &c:nums)cin>>c;
        vector<int> b(2*n+2,0);
        int ans = 0;
        for(int i = 1;i<=n;i++){
            for(int j = 1;j*nums[i-1]<2*i;j++){
                if(b[j]){
                    if(b[j]+i==j*nums[i-1])
                        ans++;
                }
            }
            b[nums[i-1]] = i;
        }
        cout<<ans<<endl;
    }
    return 0;
}  
