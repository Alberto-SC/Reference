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
        nums.push_back(0);
        vector<int> a(n);
        vector<int> b(n);
        int ans = 0;
        for(int i = 1;i<n;i++){
            a[i] = nums[i]%nums[i-1];
            b[i] = ((nums[i]+k)%(nums[i-1]+k))-a[i];
            ans +=a[i];
        }
        int f = ans,mn = 0,s = 0;
        for(int i = 1;i<n;i++){
            s+=b[i];
            if(i!=n-1)
                ans = max(ans,f+(s-mn)+((nums[i+1]%(nums[i]+k))-a[i+1]));
            else ans = max(ans,f+(s-mn));
            mn = min(mn,s+((nums[i+1]%(nums[i]+k))-a[i+1]));
        }
        cout<<ans<<endl;
    }
    return 0;
}