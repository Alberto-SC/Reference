#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

string pi = "314159265358979323846264338327950288419716939937510";
signed main(){__
    int T = 1,n;
    cin>>T;
    while(T--){
        string s;
        cin>>s;
        int ans = 0;
        ans = s.size();
        for(int i = 0;i<s.size();i++){
            if(s[i]!=pi[i]){
                ans = i;
                break;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}