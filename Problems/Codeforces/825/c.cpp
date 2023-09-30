#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n;
    cin>>T;
    while(T--){
        cin>>n;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        int l = 0,r = 0;
        int ans = 0;
        while(l<n){
            while(r<n && nums[r]>=((r-l)+1)){
                r++;
            }
            if(r ==n){
                int L = r-l;
                ans+=(L * (L+1) )/2;
                break;
            }
            while(l<r && nums[r]<((r-l)+1)){
                ans+=r-l;
                l++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}