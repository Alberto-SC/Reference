#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

signed main(){__
    int t,n,k;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        int cont = 1;
        int last = n-cont-1;
        int ans = 0;
        while(1){
            for(int i = last;i>=0;i--){
                if(nums[i]!=nums.back())break;
                cont++;
            }
            if(cont>=n)break;
            ans++;
            cont*=2;
            if(cont>=n)break;
            last = n-cont-1;
        }
        cout<<ans<<endl;
        
    }
    return 0;
}