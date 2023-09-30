#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

signed main(){__
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        int ans = 0;
        for(int i = 0;i<n;i++){
            for(int j = i;j<n;j++){
                int cont = 0;
                for(int k = i;k<=j;k++){
                    if(nums[k]== 0)cont++;
                }
                ans+=(j-i)+1+cont;
            }
        }
        cout<<ans<<endl;
    }
}