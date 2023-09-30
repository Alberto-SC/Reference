#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
    int t = 1,n;
    while(t--){
        cin>>n;
        vector<lli> nums(n);
        unordered_map<lli,lli> mp;
        mp.reserve(1024);
        mp.max_load_factor(0.25);
        for(auto &c:nums)cin>>c;
        lli ps = 0;
        lli ans = 0;
        const lli inf = 1e9+7;
        for(int i = 0;i<n;i++){
            ps+=nums[i];
            // cout<<ps<<" ";
            if(mp.count(ps)|| ps == 0){
                mp.erase(ps);
                ps-=nums[i];
                ps+=inf;
                mp[ps]++;
                i--;
                ans++;
            }
            else {

                mp[ps]++;
            }
            // cout<<ps<<" "<<i<<endl;
        }
        // cout<<n<<endl;
        // for(int i = 0;i<n;i++){
        //     if(i&1)cout<<-inf<<" ";
        //     else cout<<inf<<" ";
        // }
        // cout<<endl;
        cout<<ans<<endl;
    }
    return 0;
}

