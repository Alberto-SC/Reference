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
        vector<int> ac(n);
        ac[n-1] =nums[n-1];
        for(int i = n-2;i>=0;i--){
            ac[i] = ac[i+1]+nums[i];
        }

        int ans = 0;
        for(int i =0;i<n-1;i++){
            if(nums[i]){
                ans+=(n-(i+1))-ac[i+1];
            }
        }
        int mx = ans;
        for(int i = 0;i<n;i++){
            int l = n-(i+1);
            int nw = ans;
            if(nums[i]==0){
                nw-= i?(ac[0]-ac[i]):0;
                nw+= l-((i+1)<n?ac[i+1]:0);
                mx = max(mx,nw);
            }
            else {
                nw-= l-((i+1)<n?ac[i+1]:0);
                nw+= i?(ac[0]-ac[i]):0;
                mx = max(mx,nw);
            }

        }
        cout<<mx<<endl;
    }
    return 0;
}