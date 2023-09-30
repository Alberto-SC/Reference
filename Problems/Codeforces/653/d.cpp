#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define x first 
#define y second
int main(){__
    lli t,n,k;
    cin>>t;
    while(t--){
        cin>>n>>k;
        vector<lli> nums(n);
        for(auto &c:nums)cin>>c;
        unordered_map<lli,lli> mp;
        for(lli i = 0;i<n;i++){
            if(nums[i]<k)mp[k-nums[i]]++;
            else mp[k-(nums[i]%k)]++;
        }
        lli ans = 0;
        lli diff = -1,mx = -1;
        for(auto c:mp){
            if(!c.x)continue;
            if(c.y == mx){
                diff = max(diff,c.x);
            }
            else if(c.y>mx){
                diff = c.x;
                mx = c.y;
            }
        }
        cout<<diff<<" "<<mx<<endl;
        ans = ((mx-1)*k)+diff+1;
        cout<<ans<<endl;
    }
    return 0;
}