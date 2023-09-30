#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n,m;
    cin>>T;
    while(T--){
        cin>>n>>m;
        vector<int> nums(m);
        for(auto &c:nums)cin>>c;
        sort(nums.begin(),nums.end());
        vector<int> diff;
        for(int i = 0;i<m;i++){
            if(i ==0)diff.push_back((nums[i]-1)+(n-nums.back()));
            else diff.push_back(nums[i]-nums[i-1]-1);
        }
        sort(diff.rbegin(),diff.rend());
        int ac = 0,ans = 0;
        for(int i = 0;i<diff.size();i++){
            int x = diff[i]+-ac;
            if(x<=0)break;
            if(x==1)ans+=x;
            else ans+=x-1;
            ac+=4;
        }
        cout<<n-ans<<endl;
    }
    return 0;
}