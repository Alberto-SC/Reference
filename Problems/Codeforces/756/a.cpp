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
        bool flag = false;
        for(auto c:s){
            if((c-'0')%2==0)flag = true;
        }
        if((s.back()-'0')%2==0){
            cout<<0<<endl;
        }
        else if((s[0]-'0')%2==0){
            cout<<1<<endl;
        }
        else if(flag)cout<<2<<endl;
        else cout<<-1<<endl;

    }
    return 0;
}