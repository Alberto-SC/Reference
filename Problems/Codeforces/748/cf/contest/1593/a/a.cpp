#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n;
    cin>>t;
    while(t--){
        n = 3;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        int mx = max({nums[0],nums[1],nums[2]});
        int cont =(nums[0]==mx) + (nums[1]==mx) +(nums[2]==mx);
        if(nums[0]<mx)cout<<(mx-nums[0])+1<<" ";
        else if(cont==1)cout<<0<<" ";
        else cout<<1<<" ";
        if(nums[1]<mx)cout<<(mx-nums[1])+1<<" ";
        else if(cont==1)cout<<0<<" ";
        else cout<<1<<" ";
        if(nums[2]<mx)cout<<(mx-nums[2])+1<<" ";
        else if(cont==1)cout<<0<<" ";
        else cout<<1<<" ";
        cout<<endl;
    }
    return 0;
}  
