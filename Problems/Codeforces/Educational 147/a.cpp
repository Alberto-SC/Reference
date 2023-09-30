#include <bits/stdc++.h>
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

using namespace std;

signed main(){__
    int T,n;
    cin>>T;
    while(T--){
        string s;
        cin>>s;
        int ans = s[0]=='0'?0:1;
        for(int i = 0;i<s.size();i++){
            if(s[i]=='?'){
                if(i == 0)ans*=9;
                else ans*=10;
            }
        }
        cout<<ans<<endl;
    }
    return 0;    
}
