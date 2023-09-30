#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n,p,k;
    cin>>t;
    while(t--){
        cin>>n>>p>>k;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        vector<int> sums[k];
        sort(nums.begin(),nums.end());

        int ans  = 0,sum = 0,ac =0;
        for(int i = 0;i<k;i++){
            sum = ac;
            if(sum>p)break;
            int cont = i;
            for(int j = (i+k)-1;j<n;j+=k){
                if(sum+nums[j]<=p)
                    cont+=k,sum+=nums[j];
                else break;
            }
            ans = max(ans,cont);
            ac+=nums[i];
        }
        cout<<ans<<endl;
    }
    return 0;
}  
