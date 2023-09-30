#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

signed main(){__
    int t,n;
    cin>>t;
    while(t--){
        int x[3],y[3];
        for(int i = 0;i<3;i++){
            cin>>x[i]>>y[i];
        }
        int mx = max({y[0],y[1],y[2]});
        vector<int> xs;
        for(int i =0 ;i<3;i++)
            if(y[i]==mx)xs.push_back(x[i]);
        
        if(xs.size()==1)cout<<0<<endl;
        else{
            cout<<max(xs[0],xs[1])-min(xs[0],xs[1])<<endl;
        }
    }
}   