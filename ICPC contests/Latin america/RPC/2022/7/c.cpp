#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    string s,t;
    cin>>s>>t;

    int ans = 1;
    for(int i = 0;i<4;i++){
        if(s[i]!=t[i])ans*=2;
    }
    cout<<ans<<endl;
    return 0;
}  
