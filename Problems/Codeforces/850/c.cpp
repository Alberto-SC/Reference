#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n;
    cin>>T;
    while(T--){
        cin>>n;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        multiset<int> st(nums.begin(),nums.end());

        int id = 1;
        int ans = 0;
        while(st.size()){
            if(st.count(id)){
                st.erase(id);
            }
            else{
                int mn = *st.begin();
                ans+=mn-id;
                st.erase(st.begin());
            }
            id++;
        }
        cout<<ans<<endl;
        
    }
    return 0;
}