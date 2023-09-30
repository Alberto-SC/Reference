#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n;
    cin>>T;
    while(T--){
        string s;
        cin>>s;
        int idx = ((s[0]-'a')*25)+((s[1]-'a')+1)-(s[1]>s[0]?1:0);
        cout<<idx<<endl;
    }
    return 0;
}