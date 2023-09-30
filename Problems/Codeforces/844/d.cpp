#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

bool is_sqr(int x){
    int y = sqrt(x);
    return (y * y) == x;
}

signed main(){__
    int T = 1,n;
    cin>>T;
    while(T--){
        cin>>n;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        set<int> X;

        for(int i = 0;i<n;i++){
            for(int j = i+1;j<n;j++){
                int dif = nums[j]-nums[i];
                // cout<<i<<" "<<j<<endl;
                for(int d = 1;d*d<=dif;d++){
                    if(dif%d)continue;
                    int z = dif/d;
                    // cout<<"D: "<<d<<" "<<z<<endl;
                    if((z-d)%2 ==0){
                        int k1 = (z-d)/2;
                        int k2 = d+k1;
                        int x_i = (k2*k2)-nums[j];
                        // cout<<k1<<" "<<k2<<" "<<x_i<<endl;
                        if(x_i>=0)
                            X.insert(x_i);
                    }
                }
                // cout<<endl<<endl;
            }
        }

        int ans = 1;
        for(auto x:X){
            int res = 0;
            for(int i = 0;i<n;i++){
                if(is_sqr(nums[i]+x))res++;
            }
            ans = max(ans,res);
        }
        cout<<ans<<endl;
    }
    return 0;
}