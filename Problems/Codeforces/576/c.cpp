#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n,I;
    while(T--){
        cin>>n>>I;

        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        
        int need = (I*8)/n;
        if(need>30){
            cout<<0<<endl;
            continue;
        }
        int mxDiff = 1ll<<need;
        vector<int> v = nums;
        sort(v.begin(),v.end());
        v.erase(unique( v.begin(), v.end()),v.end());

        for(int i = 0;i<n;i++){
            nums[i] = lower_bound(v.begin(),v.end(),nums[i])-v.begin();
        }
        
        int N = v.size();
        vector<int> cont(N+3);
        vector<int> ac(N+3);



        for(int i = 0;i<n;i++)
            cont[nums[i]] ++;

        ac[0] = cont[0];
        for(int i = 1;i<=N;i++)
            ac[i] = ac[i-1]+cont[i];
        
        
        if(mxDiff>=N){
            cout<<0<<endl;
            continue;
        }
        int ans = 1e9;
        for(int i = 0;((i+mxDiff)-1)<N;i++){
            int l = i?ac[i-1]:0;
            int r = ac[N]-ac[(i+mxDiff)-1];
            ans = min(ans,l+r);
        }
        cout<<ans<<endl;
    }
    return 0;
}