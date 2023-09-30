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
        string s;
        cin>>s;
        set<string> st;
        for(int i = 0;i<n-1;i++){
          st.insert(s.substr(i,2));
        }
        cout<<st.size()<<endl;
    }
    return 0;
}