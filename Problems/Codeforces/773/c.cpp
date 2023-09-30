#include <bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'
#define int long long 

signed main(){__
    int t,n,x;
    cin>>t;
    while(t--){
        cin>>n>>x;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        multiset<int> st;
        for(int i = 0;i<n;i++)
            st.insert(nums[i]);

        int ans = 0;
        while(st.size()){
            int y = *st.begin();
            st.erase(st.find(y));
            if(st.find(y*x)==st.end())ans++;
            else   
                st.erase(st.find(y*x));
        }
        cout<<ans<<endl;
    }
}