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
        sort(nums.begin(),nums.end());
        int ans = 0;
        int cont = 0;
        int sum = 0;
        for(int i= 0;i<n;i++){
            int x= nums[i];
            while(x%2 ==0){
                x/=2;
                cont++;
            }
            sum+=x;
        }
        for(int i = 0;i<n;i++){
            int x= nums[i];
            int c = 0;
            while(x%2 == 0){
                x/=2;
                c++;
            }
            int s = sum-x;
            int y = cont-c;
            ans = max(ans,s+nums[i]*(1ll<<y));
        }
        cout<<ans<<endl;
    }
    return 0;
}