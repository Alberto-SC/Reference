#include <bits/stdc++.h>
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

using namespace std;
const int N = 1007;
signed main(){__
    int T,n;
    cin>>T;
    while(T--){
        cin>>n;

        if(n == 2){
            cout<<-1<<endl;
            continue;
        }
        if(n == 5){
            cout<<"00101\n11010\n01110\n11001\n01011"<<endl;
            continue;
        }
        if(n == 6){
            cout<<"001001\n110100\n011100\n110010\n010110\n101011"<<endl;
            continue;
        }
        
        int mn = 2;
        int cont = 1;
        while(mn<n){
            mn*=2;
            cont++;
        }

        int first = mn-1;
        vector<string> ans(n);
        
        for(int i = 0;i<n;i++){
            bitset<N> bs(first);
            first--;
            string s = bs.to_string().substr(N-n);
            ans[i] = s;
        }

        first = mn;
        for(int i = n-cont-1;i>=0;i--){
            bitset<N> bs(first);
            first++;
            string s = bs.to_string().substr(N-n);
            for(int j = 0;j<n;j++){
                ans[j][i] = s[j];
            }
        }

        for(auto c:ans)cout<<c<<endl;
        set<string> st;
        for(auto c:ans)st.insert(c);
        for(int i = 0;i<n;i++){
            string s = "";
            for(int j = 0;j<n;j++){
                s+=ans[j][i];
            }
            st.insert(s);
        }
        assert(n*2 == st.size());

        10 + 9 + 8 + 7 + 6 + 5 + 4 + 3 + 2 + 1 + 0 + -1 + -2 
    }
    return 0;
}

