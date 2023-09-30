#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n;
    while(t--){
        cin>>n;
        vector<pair<int,int>> nums(n);
        for(auto &[x,y]:nums)cin>>x>>y;
        set<pair<int,int> st;
        for(int i = 0;i<n;i++)
            st.insert(nums[i]);
        
        int last = st.begin()->first,lastdir = st.begin()->second;
        while(st.size()){
            auto x = st.begin();
            st.erase(st.begin());
            if(x.second==lastdir)last = x.first;
            else {
                st.
            }
        }
        cout<<last+10;
    }
    return 0;
}  
