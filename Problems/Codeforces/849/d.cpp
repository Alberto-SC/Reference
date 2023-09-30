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
        vector<int> pref(n);
        vector<int> suff(n);
        set<char> st;
        for(int i = 0;i<n;i++){
            if(st.count(s[i]))
                pref[i] = pref[i-1];
            else {
                st.insert(s[i]);
                pref[i] = 1+(i?pref[i-1]:0);
            }
        }
        st.clear();
        for(int i = n-1;i>=0;i--){
            if(st.count(s[i]))
                suff[i] = suff[i+1];
            else {
                st.insert(s[i]);
                suff[i] = 1+((i!=n-1)?suff[i+1]:0);
            }

        }
        int ans = 0;
        for(int i = 0;i<n-1;i++){
            int x =pref[i]+suff[i+1];
            ans = max(ans,x);
        }
    
        cout<<ans<<endl;
    }
    return 0;
}