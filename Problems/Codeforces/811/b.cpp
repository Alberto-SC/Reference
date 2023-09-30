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
        set<int> st;
        int ans = 0;
        for(int i= n-1;i>=0;i--){
            if(st.count(nums[i])){
                ans = i+1;
                break;
            }
            st.insert(nums[i]);
        }
        cout<<ans<<endl;
    }
    return 0;
}  
