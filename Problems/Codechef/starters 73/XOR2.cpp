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
        int x = 0;
        for(auto &c:nums)cin>>c,x^=c;
       
        for(int i = 0;i<n-1;i++){
            int y = nums[i]^x;
            nums[i]^=y;
            nums[i+1]^=y;
        }
        set<int> st(nums.begin(),nums.end());
        if(st.size()==1)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}