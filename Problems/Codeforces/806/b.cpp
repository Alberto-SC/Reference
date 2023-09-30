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
        string s;
        cin>>s;
        set<char> st;
        for(auto c:s){
            st.insert(c);
        }
        cout<<s.size()+st.size()<<endl;
    }
    return 0;
}  
