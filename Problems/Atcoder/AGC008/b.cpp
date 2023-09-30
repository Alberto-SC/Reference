#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

void sieve(){

}

signed main(){__
    int n,k;
    cin>>n>>k;
    vector<int> nums(n);
    int s = 0;
    for(auto &c:nums)cin>>c,c<0?c=0:c=c,s+=c;
    int x = 0;
    for(int i =0;i<k;i++)
        x+=nums[i];
    int ans = 0;
    for(int i = k;i<n;i++){
        ans = max(ans,s-x);
        x+=nums[i];
        x-=nums[i-k];
    }
    ans= max(ans,s-x);
    cout<<ans<<endl;
}
