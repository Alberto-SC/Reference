#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n;
    cin>>T;
    while(T--){
        cin>>n;
        int x = n/3;
        
        if(n%3)x++;
        if(n ==1)cout<<2<<endl;
        else 
            cout<<x<<endl;
    }
    return 0;
}