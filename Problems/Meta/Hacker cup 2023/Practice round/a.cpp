#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T= 1,n,s,d,k;
    int id = 1;
    cin>>T;
    while(T--){
        cin>>s>>d>>k;
        int a = (s*2) + (d*2);
        int b = s + (d*2);

        if(a >= k+1 && b >= k) cout<<"Case #"<<id<<": YES"<<endl;
        else cout<<"Case #"<<id<<": NO"<<endl;

        id++;
    }
    return 0;
}  

