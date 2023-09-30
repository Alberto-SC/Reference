#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'
const int mod = 998244353;

int pow_mod(int a ,int b){
    int x = 1;
    while(b){
        if(b&1)(x*=a)%=mod;
        (a*=a)%=mod;
        b>>=1;
    }
    return x;
}

signed main(){__
    int t = 1,n,k,x,m,q;
    cin>>t;
    while(t--){ 
        cin>>n>>m>>k>>q;
        vector<bool> rows(n+1,true);
        vector<bool> cols(m+1,true);
        int a = n,b = m;
        int ans = 0;
        vector<pair<int,int>> Q;
        for(int i = 0;i<q;i++){
            int x,y;
            cin>>x>>y;
            Q.push_back({x,y});
        }
        for(int i = q-1;i>=0;i--){
            auto v = Q[i];
            if(rows[v.first]|| cols[v.second])ans++;
            if(rows[v.first])a--;
            if(cols[v.second])b--;
            rows[v.first] = false;
            cols[v.second] = false;
            if(!a || !b)break;
        }
        cout<<pow_mod(k,ans)<<endl;
    }
    return 0;
}