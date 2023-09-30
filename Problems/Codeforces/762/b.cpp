#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n;
    set<int> st;
    for(int i= 1;i*i<=2000000000;i++)
        st.insert(i*i);
    for(int i = 1;i*i*i<=2000000000;i++)
        st.insert(i*i*i);
    vector<int> v;
    for(auto c:st)v.push_back(c);
    cin>>T;
    while(T--){
        cin>>n;
        int idx = upper_bound(v.begin(),v.end(),n)-v.begin();
        cout<<idx<<endl;
    }
    return 0;
}