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
        int neg = 0,pos= 0;
        for(int i = 0;i<n;i++){
            if(nums[i]<=0)neg++;
            if(nums[i]>=0)nums[i] = -nums[i]-1;
        }
        int mn = *min_element(nums.begin(),nums.end());
        if(n&1){
            for(int i = 0;i<n;i++){
                if(nums[i]==mn){
                    nums[i]= -nums[i]-1;
                    break;
                }
            }
        }
        for(auto c:nums)cout<<c<<" ";
        cout<<endl;

    }
    return 0;
}  
