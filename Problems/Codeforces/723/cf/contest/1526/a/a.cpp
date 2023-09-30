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
        vector<int> nums(2*n);
        for(auto &c:nums)cin>>c;
        sort(nums.begin(),nums.end());
        int l = 0,r = (2*n)-1; 
        for(int i = 0;i<2*n;i++){
            if(i&1)cout<<nums[l++]<<" ";
            else cout<<nums[r--]<<" ";
        }
        cout<<endl;
    }
    return 0;
}  
