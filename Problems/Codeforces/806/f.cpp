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
        vector<int> nums(n+1);
        for(int i= 1;i<=n;i++)
            cin>>nums[i];
        vector<int> ac(n+1);
        ac[1] = nums[1]==0;
        int ans = 0;
        for(int i = 2;i<=n;i++){
            ac[i] = ac[i-1];
            if(nums[i]<i){
                if(nums[i]-1>=0)
                    ans+=ac[nums[i]-1];
                ac[i]++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}  
