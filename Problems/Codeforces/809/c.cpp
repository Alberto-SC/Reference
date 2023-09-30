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

        if(n&1){
            int ans = 0;
            for(int i =1;i<n;i+=2){
                int diff = max({0ll,(nums[i-1]-nums[i])+1,(nums[i+1]-nums[i])+1});
                ans+=diff;
            }
            cout<<ans<<endl;
        }
        else{
            int ans = 1e18;
            vector<int> p,s;
            p.push_back(0);
            for(int i =1;i<n-1;i+=2){
                int diff = max({0ll,(nums[i-1]-nums[i])+1,(nums[i+1]-nums[i])+1});
                p.push_back(diff+p.back());
                p.push_back(0+p.back());
            }
            p.push_back(p.back());

            s.push_back(0);
            for(int i = n-2;i>=1;i-=2){
                int diff = max({0ll,(nums[i-1]-nums[i])+1,(nums[i+1]-nums[i])+1});
                s.push_back(diff+s.back());
                s.push_back(0+s.back());      
            }
            s.push_back(s.back());

            reverse(s.begin(),s.end());
            
            ans = min(p.back(),s[0]);
            for(int i = 1;i<n;i+=2){
                if(i+3<=n-2)
                    ans = min(ans,p[i]+s[i+3]);
            }

            cout<<ans<<endl;

        }
    }
    return 0;
}