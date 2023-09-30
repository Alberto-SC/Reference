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
        cout<<2<<endl;
        vector<bool> v(n+1,false);
        int cont = 0;
        for(int i = 1;i<=n;i++){
            if(v[i])continue;
            int x = i;
            while(x<=n){
                cout<<x<<" ";
                v[x] = true;
                x*=2;
            }

        }
        cout<<endl;

    }
    return 0;
}