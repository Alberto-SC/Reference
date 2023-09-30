#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n;
    string s;
    cin>>s;
    n = s.size();
    int ans = -2;
    for(int i = n-1;i>=0;i--){
        if(s[i]=='a'){
            ans = i;
            break;
        }
    }
    cout<<ans+1<<endl;
    return 0;
}