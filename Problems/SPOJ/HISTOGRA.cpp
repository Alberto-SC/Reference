#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define int long long
signed main(){__
    int n;
    while(1){
        cin>>n;
        if(n==0)break;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        stack<pair<int,int>> st;
        vector<int> fr(n,n);
        vector<int> fl(n,-1);
        for(int i = 0;i<n;i++){
            while(!st.empty() && st.top().first>nums[i]){
                auto top = st.top();
                fr[top.second]= i;
                st.pop();
            }
            st.push({nums[i],i});
        }
        while(!st.empty())
            st.pop();

        for(int i = n-1;i>=0;i--){
            while(!st.empty() && st.top().first>nums[i]){
                auto top = st.top();
                fl[top.second]= i;
                st.pop();
            }
            st.push({nums[i],i});
        }
        int ans = 0;
        for(int i = 0;i<n;i++){
            ans = max(ans,nums[i]*(fr[i]-(fl[i]+1)));
        }
        cout<<ans<<endl;
    }
    return 0;
}