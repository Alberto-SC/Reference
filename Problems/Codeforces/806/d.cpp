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
        vector<string> S(n);
        for(auto &c:S)cin>>c;
        vector<int> ans(n);
        set<string> st;
        for(int j = 0;j<n;j++){
                st.insert(S[j]);
        }
        for(int i = 0;i<n;i++){
            string x = "";
            for(int j =0;j<S[i].size()-1;j++){
                x+=S[i][j];
                if(st.count(x) && st.count(S[i].substr(j+1)))ans[i] = 1;
            }
        }
        for(auto c:ans)cout<<c;
        cout<<endl;
    }
    return 0;
}  
