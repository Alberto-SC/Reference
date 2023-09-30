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
        int mx = 0;
        for(int i = 0;i<n;i++){
            mx = max(mx,(long long )s[i]-'a');
        }
        cout<<mx+1<<endl;
    }
    return 0;
}