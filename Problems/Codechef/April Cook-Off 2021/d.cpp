#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        vector<int> copy(nums);
        sort(copy.begin(),copy.end());
        int last = copy[0];
        vector<int> u;
        u.push_back(last);
        for(int i = 0;i<n;i++){
            if(copy[i]!= last){
                last = copy[i];
                u.push_back(last);
            }
        }
        vector<vector<int>> A(n);
        stack<int> st;
        for(int i = 0;i<n;i++){
            nums[i] = lower_bound(u.begin(),u.end(),nums[i])-u.begin();
            while(!st.empty() && st.top()>nums[i]){
                A[st.top()].push_back(nums[i]);
                A[nums[i]].push_back(st.top());
                st.pop();
            }
            st.push(nums[i]);
        }
        for(int i = 0;i<n;i++){
            cout<<i<<" -> "; 
            for(auto c:A[i])cout<<c<<" ";
            cout<<endl;
        }
    }
    return 0;
}  
