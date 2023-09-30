#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

const int mod = 1e9+7;
signed main(){__
    int t,n,a,b,c,d;
    cin>>t;
    while(t--){
        cin>>n;
        int l,r,ans=1;
        vector<int> v(n);
        vector<int> pos(n+1);
        for(int i=0;i<n;i++){
            cin>>v[i];
            pos[v[i]]=i;
        }

        l = r = pos[0];

        for(int i=1;i<n;i++){
            if(pos[i]<l) l = pos[i];
            else if(pos[i]>r) r = pos[i];
            else (ans*=(((r-l)+1)-i))%=mod;
        }
        cout<<ans<<endl;
    }
}
