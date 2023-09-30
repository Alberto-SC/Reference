#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n,m;
    cin>>T;
    while(T--){
        cin>>n>>m;
        vector<int> a(n),b(m);
        int s1 = 0,s2 = 0;
        for(auto &c:a)cin>>c,s1+=c;
        for(auto &c:b)cin>>c,s2+=c;
        if(s1>s2)cout<<"Tsondu"<<endl;
        else if(s2>s1)cout<<"Tenzing"<<endl;
        else cout<<"Draw"<<endl;

    }
    return 0;
}