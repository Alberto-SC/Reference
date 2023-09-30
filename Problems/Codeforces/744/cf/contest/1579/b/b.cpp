#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

struct ans{
    int l,r,d;
};

signed main(){__
	int t= 1,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        vector<int> snums = nums;
        sort(snums.begin(),snums.end());
        vector<ans> res;
        for(int i = 0;i<n;i++){
            if(nums[i]==snums[i])continue;
            else {
                int idx = 0;
                for(int j =i;j<n;j++){
                    if(nums[j] == snums[i]){
                        idx  = j;
                        break;
                    }
                }
                rotate(nums.begin()+i,nums.begin()+idx,nums.end());
                res.push_back({i+1,n,idx-i});
            }
        }   
        cout<<res.size()<<endl;
        for(auto c:res)cout<<c.l<<" "<<c.r<<" "<<c.d<<endl;
    }
    return 0;
}  
