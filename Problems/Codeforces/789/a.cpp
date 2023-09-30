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
        int cont = 0;
        set<int> st;
        for(auto &c:nums)cin>>c,cont+=c==0,st.insert(c);

        if(cont || st.size()!=n){
            cout<<n-cont<<endl;
        }else{
            cout<<n+1<<endl;
        }
    }
    return 0;
}