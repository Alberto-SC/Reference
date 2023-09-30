#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n,m;
    cin>>T;
    while(T--){
        cin>>n>>m;
        vector<int> a(n);
        vector<int> b(m);
        multiset<int> st;
        for(auto &c:a)cin>>c,st.insert(c);
        for(auto &c:b)cin>>c;
        for(int i = 0;i<m;i++){
            st.erase(st.begin());
            st.insert(b[i]);
        }
        int ans = 0;
        for(auto c:st){
            ans+=c;
        }
        cout<<ans<<endl;
    }
    return 0;
}