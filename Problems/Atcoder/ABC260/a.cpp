#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);



signed main(){__
    int T = 1,n;
    int z;
    while(T--){
        string s;
        cin>>s;
        if(s[0]!=s[1] && s[0]!=s[2])cout<<s[0]<<endl;
        else if(s[1]!=s[0] && s[1]!=s[2])cout<<s[1]<<endl;
        else if(s[2]!=s[0] && s[2]!=s[1])cout<<s[2]<<endl;
        else cout<<-1<<endl;
    }
    return 0;
}
