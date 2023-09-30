#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n,m;
    while(T--){
        cin>>n>>m;
        string s;
        vector<int> v(n);
        for(int i = 0;i<n;i++){
            cin>>s;
            int x = 0;
            for(int j = 0;j<m;j++){
                if(s[j]=='o')x|=(1<<j);
            }
            v[i] = x;
        }

        int ans = 0;
        int valid = (1<<m)-1;
        for(int i = 0;i<n;i++){
            for(int j = i+1;j<n;j++){
                if((v[i]|v[j]) == valid)ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
