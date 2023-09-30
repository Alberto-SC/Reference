#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
lli lcm(lli a,lli b){
    return b*(a/__gcd(a,b));
}
int main(){__
	int t= 1,n;
    while(t--){
        cin>>n;
        vector<lli> nums(n);
        for(auto &c:nums)cin>>c;
        lli G,L,ans;
        ans = lcm(nums[0],nums[1]);
        G = __gcd(nums[0],nums[1]);
        for(int i = 2;i<n;i++){
            L = lcm(nums[i],G);
            G = __gcd(G,nums[i]);
            ans = __gcd(ans,L);
        }
        cout<<ans<<endl;
    }
    return 0;
}  

