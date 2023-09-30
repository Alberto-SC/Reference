#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n;
    while(T--){
        string s;
        cin>>n;
        cin>>s;
        s = "$"+s;
        for(int i = 1;i<=n-1;i++){
            int x = n-i;
            for(int l = 1;l+i<=n;l++){
                if(s[l]== s[l+i]){
                    x = l-1;
                    break;
                }
            }
            cout<<x<<endl;
        }

    }
    return 0;
}