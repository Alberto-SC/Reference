#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n;
    while(T--){
        cin>>n;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        multiset<int> st; 
        for(int i = 0;i<n;i++){
            st.insert(nums[i]);
        }
        int ans = 0;
        while(st.size()>1){
            ans++;
            auto mn = *st.begin();
            auto mx = *st.rbegin();
            int last = mx;
            mx = mx%mn;
            
            st.erase(st.find(last));
            if(mx != 0)
                st.insert(mx);
        }
        cout<<ans<<endl;
    }
    return 0;
}