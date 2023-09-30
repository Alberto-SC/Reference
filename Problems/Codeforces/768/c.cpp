#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

signed main(){__
    int t,n,k;
    cin>>t;
    while(t--){
        cin>>n>>k;
        vector<int> st(n);
        int z = n-1;
        if(k!=n-1){
            int NX = k^z;
            cout<<0<<" "<<k<<endl;
            cout<<NX<<" "<<z<<endl;
            for(int i = 1;i<n-1;i++){
                if(i==k)continue; 
                cout<<i<<" "<<i^z<<endl;
            }
        }
        else {
            if(n==4){cout<<-1<<endl;continue;}
            for
        }
    }
    return 0;
}