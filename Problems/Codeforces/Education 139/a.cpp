#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1;
    cin>>T;
    while(T--){
        string n;
        cin>>n;
        int x = (n.size()-1)*9;
        x+=n[0]-'0';
        cout<<x<<endl;
    }
    return 0;
}