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
        int ans = 0;
        for(int i = 0;i<n;i++){
            vector<int> f(10);
            set<char> st;
            for(int j = i;j<min((int)s.size(),i+107);j++){
                f[s[j]-'0']++;
                st.insert(s[j]);
                bool flag = true;
                for(int k = 0;k<=9;k++){
                    if(f[k]>st.size())flag = false;
                }
                if(flag)ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}