#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n;
    cin>>T;
    while(T--){
        string s,t;
        cin>>s;
        cin>>t;
        bool flag = false;
        for(auto c:t){
            if(c =='a')flag =true;
        }
        if(flag && t.size()>1)cout<<-1<<endl;
        else if(flag)cout<<1<<endl;
        else cout<<(1ll<<s.size())<<endl;
    }
    return 0;
}