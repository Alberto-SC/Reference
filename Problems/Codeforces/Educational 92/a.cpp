#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
    lli t,n,l,r;
    cin>>t;
    while(t--){
        cin>>l>>r;
        lli x =l*2;
        if(x<=r)cout<<l<<" "<<x<<endl;
        else cout<<-1<<" "<<-1<<endl; 
    }
    return 0;
}