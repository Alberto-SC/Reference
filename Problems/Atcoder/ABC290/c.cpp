#include <bits/stdc++.h>
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

using namespace std;

signed main(){__
    int n,k;
    cin>>n>>k;
    vector<int> nums(n);
    for(auto &c:nums)cin>>c;
    set<int> st(nums.begin(),nums.end());
        
    int ans = k;
    for(int i = 0;i<k;i++){
        if(!st.count(i)){
            ans = i;
            break;
        }
    }
    cout<<ans<<endl;
    
    return 0;
}
