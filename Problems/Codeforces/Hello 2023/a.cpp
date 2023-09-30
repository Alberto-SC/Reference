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
        int r = 0,l = 0;
        int ans = 0;
        for(int i = 0;i<n-1;i++){
            r +=s[i]=='R';
            l +=s[i]=='L';
            if(s[i]=='L' && s[i+1]=='R'){ans = i+1;}
        }
        r+= s[n-1]=='R';
        l+= s[n-1]=='L';
        if(!r || !l)cout<<-1<<endl;
        else{
            cout<<ans<<endl;
        }
    }
    return 0;
}