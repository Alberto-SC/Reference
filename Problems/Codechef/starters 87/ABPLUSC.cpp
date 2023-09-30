#include <bits/stdc++.h>
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl '\n'

using namespace std;

const int MAX = 1000000;

signed main(){__
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;

        int x = sqrt(n);
        int y = n/x;
        if(n == 1)
            cout<<-1<<endl;
        else if(x*y == n && x <=MAX && (y-1)<=MAX )
            cout<<x<<" "<<y-1<<" "<<x<<endl;
        else if(x <=MAX && y<=MAX && n-(x*y)<=MAX)
            cout<<x<<" "<<y<<" "<<n-(x*y)<<endl;
        else cout<<-1<<endl;


    }
    return 0;
}