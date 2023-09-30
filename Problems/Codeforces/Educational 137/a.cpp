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
        set<int> st;
        for(auto &c:nums)cin>>c,st.insert(c);
        int x = 10-st.size();
        cout<< 6*((x*(x-1))/2)<<endl;
    }
    return 0;
}