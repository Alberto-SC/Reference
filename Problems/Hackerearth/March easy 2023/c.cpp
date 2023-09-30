#include <bits/stdc++.h>
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

using namespace std;

signed main(){__
    int T,n;
    cin>>T;
    while(T--){
        cin>>n;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        int cont = 0;
        int ans = 0;
        for(int i = 0;i<n;i++){
            if(nums[i]<=0){
                ans+=(cont*(cont+1))/2;
                cont = 0;

            }
            else{
                cont++;
            }
        }
        ans+=(cont*(cont+1))/2;
        cout<<ans<<endl;
    }
    return 0;
}

