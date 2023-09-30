#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define endl '\n'
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
signed main(){__
    int t,x,y;
    cin>>t;
    while(t--){
        cin>>x>>y;
        if(y>x){
            if(y%2==0){
                int init = (y-1)*(y-1)+1;
                cout<<init+(x-1)<<endl;
            }
            else{
                int init = y*y;
                cout<<init-(x-1)<<endl;
            } 
        }
        else{
            if(x%2==0){
                int init = x*x;
                cout<<init-(y-1)<<endl;
            }
            else{
                int init = (x-1)*(x-1)+1;
                cout<<init+(y-1)<<endl;
            } 
        }
    }
    return 0;
}