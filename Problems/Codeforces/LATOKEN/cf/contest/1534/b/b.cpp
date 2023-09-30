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
        vector<int> nums;
        nums.push_back(0);
        for(int i = 0;i<n;i++){
            int x;
            cin>>x;
            nums.push_back(x);
        }
        nums.push_back(0);
        int cont = 0;
        for(int i = 1;i<=n;i++){
            if(nums[i]>nums[i-1] &&nums[i]>nums[i+1]){
                cont+=nums[i]-max(nums[i-1],nums[i+1]);
                nums[i] = max(nums[i-1],nums[i+1]);
            }
        }
        int ans = 0;
        for(int i = 1;i<=n+1;i++){
            ans+=abs(nums[i]-nums[i-1]);
        }
        cout<<ans+cont<<endl;
    }
    return 0;
}  
