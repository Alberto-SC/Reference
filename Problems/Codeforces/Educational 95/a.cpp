#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
    lli t = 1,n,x,y,k;
    cin>>t;
    while(t--){
        cin>>x>>y>>k;
        lli a = y*k;
        lli need = k+a;
        need--;
        // cout<<need<<endl;
        if(need%(x-1) == 0)cout<<(need/(x-1))+k<<endl;
        else cout<<(need/(x-1))+k+1<<endl;
        // cout<<ceil(need/((x-1)*1.0))<<endl;
        // cout<<ceil((need)/((x-1)*1.0))<<endl; 

    }
    return 0;
}

