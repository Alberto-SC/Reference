#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

struct ans{
    int type,i,j;
};
signed main(){__
	int t= 1,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        bool flag = true;
        vector<ans> res;
        for(int i = 1;i<=n;i+=2){
            nums[i-1] = nums[i-1]+nums[i];
            nums[i] = nums[i]-nums[i-1];
            nums[i-1] = nums[i-1]+nums[i];
            nums[i-1] = nums[i-1]+nums[i];
            nums[i] = nums[i]-nums[i-1];
            nums[i-1] = nums[i-1]+nums[i];
            res.push_back({1,i,i+1});
            res.push_back({2,i,i+1});
            res.push_back({1,i,i+1});
            res.push_back({1,i,i+1});
            res.push_back({2,i,i+1});
            res.push_back({1,i,i+1});
        }
        cout<<res.size()<<endl;
        for(auto c:res)cout<<c.type<<" "<<c.i<<" "<<c.j<<endl;
    }
    return 0;
}  
