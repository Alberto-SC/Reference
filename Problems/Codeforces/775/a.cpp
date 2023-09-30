#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

signed main(){__
    int t,n,s;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int>nums(n);
        for(auto &c:nums)cin>>c;
        int cont = 0,ans = 0;
        for(int i = 0;i<n;i++){
            if(nums[i]== 0)cont++;
            if(nums[i]== 1){
                if(cont)
                ans+=cont+1;
                cont = 0;
            }
        }
        cout<<ans<<endl;
    }
}   