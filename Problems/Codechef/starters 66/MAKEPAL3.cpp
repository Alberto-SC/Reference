#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

int solve(vector<int> &v){  
    int n = v.size();
    int ans = v[0];
    int mx = v[0];
    for(int i = 1;i<n;i++){
        if(v[i]>mx){
            ans+=v[i]-mx; 
            mx = v[i];
        }
        else {
            mx = v[i];
        }
    }
    return ans;
}   

signed main(){__
    int T = 1,n;
    cin>>T;
    while(T--){
        cin>>n;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        vector<int> L,R;
        for(int i = 0;i<(n/2);i++){
            int x = nums[i];
            int y = nums[(n-1)-i];
            if(x>y){
                R.push_back(x-y);
                L.push_back(0);
            }
            else if(x<y){
                L.push_back(y-x);
                R.push_back(0);
            }
            else {
                L.push_back(0);
                R.push_back(0);
            }
        }
        int ans = solve(L);
        ans +=solve(R);
        cout<<ans<<endl;
    }
    return 0;
}