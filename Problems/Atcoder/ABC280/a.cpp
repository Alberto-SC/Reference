#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n,m;
    while(T--){
        cin>>n>>m;
        int ans = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                char c;
                cin>>c;
                if(c=='#')ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}