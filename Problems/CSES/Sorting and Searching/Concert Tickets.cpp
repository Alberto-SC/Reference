#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n,m;
    while(T--){
        cin>>n>>m;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        multiset<int> st(nums.begin(),nums.end());
        for(int i = 0;i<m;i++){
            int x;
            cin>>x;
            auto c = st.lower_bound(x);
            if((*c)==x){
                cout<<x<<endl;
                st.erase(c);
            }
            else if(c == st.begin()){
                cout<<-1<<endl;
            }
            else{
                c--;
                cout<<(*c)<<endl;
                st.erase(c);
            }
        }
    }
    return 0;
}