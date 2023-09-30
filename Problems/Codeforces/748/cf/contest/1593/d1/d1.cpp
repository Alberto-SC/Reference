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
        sort(nums.begin(),nums.end());
        vector<int> diff;

        for(int i = 1;i<n;i++)
            diff.push_back(nums[i]-nums[0]);
        int gcd = 0;
        for(int i = 0;i<diff.size();i++)
            gcd = __gcd(gcd,diff[i]);
        
        if(gcd ==0)cout<<-1<<endl;
        else cout<<gcd<<endl;
    }
    return 0;
}  
