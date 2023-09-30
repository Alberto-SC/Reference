#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);


signed main(){__
	int t= 1,n,k;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        sort(nums.begin(),nums.end());
        if(nums.size()==1 && nums[0]>1)cout<<"NO"<<endl;
        else if(nums.size()==1 && nums[0]==1)cout<<"YES"<<endl;
        else{
            if(nums.back()-nums[n-2]>1)cout<<"NO"<<endl;
            else cout<<"YES"<<endl;
        }
    }
    return 0;
}  
