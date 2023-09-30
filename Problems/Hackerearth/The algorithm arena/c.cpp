#include <bits/stdc++.h>
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

using namespace std;

signed main(){__
    int T,n;
    cin>>n;
    vector<int> nums(n);
    for(auto &x:nums)cin>>x;
    
    stack<int> st;
    vector<int> R(n,-1);
    for(int i = n-1;i>=0;i--){
        while(st.size() && nums[st.top()]<nums[i]){
            R[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    for(int i = 0;i<n;i++){
        R[i] = i-R[i];
        cout<<R[i]<<" ";
    }
    cout<<endl;
    
}


