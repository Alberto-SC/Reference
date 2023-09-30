#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n,t;
    cin>>T;
    while(T--){
        cin>>n>>t;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        int ans = (t*(t-1))/2;

        vector<int> ac(n);
        ac[0] = nums[0];
        for(int i = 1;i<n;i++){
            ac[i]+=ac[i-1]+nums[i];
        } 
        int mx = 0;
        for(int i = 0;i<n;i++){
            int x = ac[min(n-1,i+(t-1))]-(i?ac[i-1]:0);
            mx = max(mx,x);
        }
        if(t<=n){
            cout<<mx+ans<<endl;
        }
        else{
            ans = ac[n-1];
            int x = t-(n-1);
            ans+=x-1;
            for(int i = 0;i<n-1;i++){
                ans+=x;
                x++;
            }
            cout<<ans<<endl;
        }    
    }
    return 0;
}