#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

signed main(){__
    int n;
    cin>>n;
    vector<int> nums(n);
    for(auto &c:nums)cin>>c;
    vector<int> R(n,n);
    vector<int> L(n,-1);

    stack<pair<int,int>> st;    
    for(int i =0;i<n;i++){ x 
        while(st.size() && st.top().first>nums[i]){
            auto x = st.top();
            st.pop();
            R[x.second] = i;
        }
        st.push({nums[i],i});
    }
    while(st.size()){st.pop();}
    for(int i = n-1;i>=0;i--){
        while(st.size( ) && st.top().first>nums[i]){
            auto x = st.top();
            st.pop();
            L[x.second] = i;
        }
        st.push({nums[i],i});
    }
    int ans = 0;
    for(int i = 0;i<n;i++){
        ans +=nums[i]*(R[i]-i)*(i-L[i]);
    }
    cout<<ans<<endl;
}