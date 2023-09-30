#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n,k;
    cin>>T;
    while(T--){
        cin>>n>>k;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        sort(nums.begin(),nums.end());
        int ans = 0;
        for(int i = 0;i<n-(k*2);i++){
            ans+=nums[i];
        }
        map<int,int> f;
        int l = n-(k*2),r = n-1;
        for(int i =l;i<n;i++){
            f[nums[i]]++;
        }
        int mx = 0;
        for(auto c:f){
            mx = max(mx,c.second);
        }
        if(mx>k){
            ans+=(mx-((k*2)-mx))/2;
        }
        cout<<ans<<endl;
    }
    return 0;
}