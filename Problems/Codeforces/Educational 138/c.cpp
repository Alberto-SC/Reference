#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

bool check(int x,vector<int> nums){
    multiset<int> st;
    int n = nums.size();
    for(int i = 0;i<n;i++){
        st.insert(nums[i]);
    }
    for(int i = 1;i<=x;i++){
        int y = x-i+1;
        while(st.size() && (*(st.rbegin()))>y){
            st.erase(--st.end());
        }
        // cout<<(*st.rbegin())<<endl;
        if(st.size())
            st.erase(--st.end());
        else return false;
        if(st.size()==0)continue;
        int z = *st.begin();
        z+=y;
        st.erase(st.begin());
        st.insert(z);

    }
    return true;
}

signed main(){__
    int T = 1,n;
    cin>>T;
    while(T--){
        cin>>n;
        vector<int> nums(n);
        int cont  = 0;
        for(auto &c:nums)cin>>c;
        int ans = 0;
        for(int i = 1;i<=n;i++){
            if(check(i,nums))ans = max(ans,i);
        }
        cout<<ans<<endl;
    }
    return 0;
}