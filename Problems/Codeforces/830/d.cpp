#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n,q;
    while(T--){
        cin>>q;
        map<int,int> mp;

        set<int> st;
        char op;
        int x;
        while(q--){
            cin>>op>>x;
            if(op =='+')
                st.insert(x);
            else{
                int mul = 1;
                if(mp.count(x)){
                    mul = mp[x];
                }
                while(st.count(x*mul)){
                    mul++;
                }
                cout<<x*mul<<endl;
                mp[x] = mul;
            }
        }
    }
    return 0;
}