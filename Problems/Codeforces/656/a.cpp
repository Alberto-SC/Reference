#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

int main(){__
    int t = 1,n,x,y,z;
    cin>>t;
    while(t--){
        cin>>x>>y>>z;
        if(x!= y && x != z && y != z){cout<<"NO"<<endl;continue;}
        if(x== y && x == z && y == z){
            cout<<"YES"<<endl;
            cout<<x<<" "<<x<<" "<<x<<endl;
            continue;
        }
        if((x == y && z>x) || (x == z && y>x) || (y == z && x>y))
            cout<<"NO"<<endl;
        else {
            cout<<"YES"<<endl;
            if(x == y)cout<<x<<" "<<z<<" "<<1<<endl;
            if(x == z)cout<<x<<" "<<y<<" "<<1<<endl;
            if(y== z)cout<<y<<" "<<x<<" "<<1<<endl;
        }
        
    }
    return 0;
}