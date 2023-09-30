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
        for(int i = 0;i<n;i++){
            int x = min(nums[i],k);
            nums[i]-=x;
            k-=x;
            nums.back()+=x;
        }
        for(auto c:nums)cout<<c<<" ";
        cout<<endl;
    }
    return 0;
}  
