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
        multiset<int> st;
        for(int i = 1;i<n;i++){
            st.insert(nums[i]);
        }
        int last = nums[0];
        while(st.size()){
            while(st.size() && (*st.begin())<=last){
                st.erase(st.begin());
            }
            if(!st.size())break;
            int nxt = *st.begin();
            st.erase(st.begin());
            last+=((nxt-last)+1)/2;
        }
        cout<<last<<endl;
    }
    return 0;
}