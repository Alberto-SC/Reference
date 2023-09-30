#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);


signed main(){__
    int T = 1,n,k;
    cin>>n>>k;
    vector<int> nums(n);
    for(auto &c:nums)cin>>c,c--;
    set<int> st;
    vector<int> ans(n,-1);
    vector<int> nxt(n,-1);
    vector<int> sz(n,1);

    for(int i = 0;i<n;i++){
        auto x = st.lower_bound(nums[i]);
        if(x == st.end()){
            st.insert(nums[i]);
        }
        else{
            st.erase(x);
            nxt[nums[i]] = *x;
            sz[nums[i]] = sz[*x]+1;
            st.insert(nums[i]);
        }
        if(sz[nums[i]]==k){
            st.erase(nums[i]);
            int u = nums[i];
            for(int j = 0;j<k;j++){
                ans[u] = i+1;
                u = nxt[u];
            }
        }
    }
    for(auto c:ans)cout<<c<<endl;
    cout<<endl;
    return 0;
}
