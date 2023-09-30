#include <bits/stdc++.h>
 
using namespace std;
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define int long long
signed main() {__
    int n,m;
    while(cin>>n>>m){
        int x =1;
        for(int i = 1;i<=n;i++)
            x*=i;
        int y =1;
        for(int i = 1;i<=m;i++)
            y*=i;

        cout<<x+y<<endl;
    }
    return 0;
}