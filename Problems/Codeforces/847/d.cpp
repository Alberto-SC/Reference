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
        sort(nums.begin(),nums.end());
        for(int i = 0;i<n;i++){
            if(st.count(nums[i]-1)){
                st.erase(st.find(nums[i]-1));
                st.insert(nums[i]);
            }
            else{
                st.insert(nums[i]);
            }
        }
        cout<<st.size()<<endl;
    }
    return 0;
}