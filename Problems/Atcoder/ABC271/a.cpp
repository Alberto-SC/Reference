#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n;
    while(T--){
        int n;
        cin>>n;
        int x = n/16;
        n%=16;
        if(x>=10)cout<<char('A'+x-10);
        else cout<<char('0'+x);
        if(n>=10)cout<<char('A'+n-10);
        else cout<<char('0'+n);
        cout<<endl;
    }
    return 0;
}