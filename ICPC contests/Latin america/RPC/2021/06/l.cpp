#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
// #define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

signed main(){__
	int t= 1,n;
    cin>>t;
    int id = 1;
    vector<int> ans;
    while(t--){
        cin>>n;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        vector<int> firstleft(n,-1);
        ordered_set st;
        vector<int> sufmax(n);
        for(int i =n-1;i>=0;i--){
            sufmax[i] = max(i==n-1?0:sufmax[i+1],nums[i]);
        }
        st.insert(nums[0]);
        bool flag = false;
        for(int i = 1;i<n-1;i++){
            int pos = st.order_of_key(nums[i]);
            int num = *st.find_by_order(pos);
            // cout<<pos<<" "<<num<<endl;
            if(pos ==st.size()){
                st.insert(nums[i]);
                continue;
            }
            st.insert(nums[i]);
            if(sufmax[i+1]>num){
                flag = true;
                break;
            }
        }
        if(flag)ans.push_back(id);
        id++;
    }
    cout<<ans.size()<<endl;
    for(auto c:ans)cout<<c<<endl;
    return 0;
}  
