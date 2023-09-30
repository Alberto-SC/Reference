#include <bits/stdc++.h>
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define endl '\n'

using namespace std;
const int mod = 1e9+7;
signed main(){__
    int T;
    cin>>T;
    while(T--){
        int n,m;
        cin>>n>>m;
        vector<int> p(n);
        vector<int> a(n);
        for(auto &c:p)cin>>c,c--;
        for(auto &c:a)cin>>c;
        
        vector<int> final(n);
        iota(final.begin(),final.end(),0);

        for(int i = 0;i<n;i++){
            final[i] = final[p[i]];
        }

        set<int> st(final.begin(),final.end());
        int ans = 1;
        set<int> st2;
        int cont = 0;
        for(int i = 0;i<n;i++){
            if(!st.count(i)){
                if(a[i]== 0)ans*=m;
                cont++;
                ans%=mod;
            }
            else{
                st2.insert(a[i]);
            }
        }
        if(st2.size()>=3)ans = 0;
        else if(st2.size()==1){
            if(st2.count(0))ans*=m;
            ans%=mod;
        }
        else if(st2.size()==2){
            if(!st2.count(0))ans = 0;
        }            
        cout<<ans<<endl;
    }
    return 0;
}
 



