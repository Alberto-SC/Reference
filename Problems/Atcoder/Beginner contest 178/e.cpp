#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

int main(){__
    lli t = 1,n,x,y;
    while(t--){
        cin>>n;
        lli minz= 2e9,maxz = -2e9,miny = 2e9,maxy = -2e9;
        for(int i = 0;i<n;i++){
            cin>>x>>y;
            minz  = min(minz,x+y);
            maxz  = max(maxz,x+y);
            miny  = min(miny,x-y);
            maxy  = max(maxy,x-y);
        }
        cout<<max(maxz-minz,maxy-miny)<<endl;
    }
    return 0;
}

  