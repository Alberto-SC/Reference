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
        string s;
        cin>>s;
        int c1 = 0,c0 = 0;
        for(int i = 0;i<n;i++){
            if(s[i]== '0')c0++;
            else c1++;
        }

        int ans = min(c1,c0+1);
        cout<<ans<<endl;
    }
    return 0;
}