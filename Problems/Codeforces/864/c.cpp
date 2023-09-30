#include <bits/stdc++.h>
using namespace std;
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n,m;
    cin>>T;
    while(T--){
        cin>>n>>m;
        int first,second,third;

        cout<<"? 1 1"<<endl;
        cin>>first;

        int x = 1+first;
        int y = 1+first;
        int a,b;
        int i,j;
        if(x<=n && y<=m){
            cout<<"? "<<x<<" "<<y<<endl;
            cin>>second;
            a = x,b = y-second;
            i = x-second,j = y;
            cout<<"? "<<a<<" "<<b<<endl;
            cin>>third;
            if(third ==0)cout<<"! "<<a<<" "<<b<<endl;
            else cout<<"! "<<i<<" "<<j<<endl; 
        }
        else if(n<x){
            cout<<"? "<<n<<" "<<y<<endl;
            cin>>second;

            cout<<"! "<<n-second<<" "<<y<<endl;
        }
        else if(m<y){
            cout<<"? "<<x<<" "<<m<<endl;
            cin>>second;
            cout<<"! "<<x<<" "<<m-second<<endl;
        }

    }
    return 0;
}