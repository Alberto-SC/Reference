#include <bits/stdc++.h>
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n';

using namespace std;

signed main(){__
    int T,n,m;
    cin>>T;
    while(T--){
        cin>>n>>m;
        vector<int> nums(m);
        vector<int> ans(n+1,-1);
        for(auto &c:nums)cin>>c; 
            
        set<int> st;
        int id = n;
        for(int i = 0;i<m;i++){
            if(id<0)break;
            if(!st.count(nums[i]))ans[id--] = i+1;
            st.insert(nums[i]);
        }
        for(int i = 1;i<=n;i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}

