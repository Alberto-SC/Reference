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
        string s;
        cin>>s;
        int a = 0,b = 0,ans = 1e9;
        for(int i = 0;i<k;i++){
            if(s[i]== 'B')a++;
            else b++;
        }
        ans = min(ans,b);
        for(int i = k;i<n;i++){
            if(s[i-k] == 'B')a--;
            else if(s[i-k]== 'W')b--;
            if(s[i]== 'B')a++;
            else b++;
            ans = min(ans,b);
        }

        cout<<ans<<endl;

    }
    return 0;
}
