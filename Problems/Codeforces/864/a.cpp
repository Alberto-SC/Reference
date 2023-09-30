#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1;
    cin>>T;
    while(T--){
        int n,m;
        cin>>n>>m;

        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        x1--,y1--,x2--,y2--;
        
        if((x1 ==0 && y1==0) || (x1 == n-1 && y1 == m-1) || (x2 == 0 && y2 == 0) || (x2 == n-1 && y2 == m-1) ||(x1==0 && y1==m-1) || (x1 == n-1 && y1 == 0) || (x2 == 0 && y2 == m-1) || (x2 == n-1 && y2 == 0)){
            cout<<2<<endl;
        }
        else if(x1 ==0 || y1 ==0 || x1 == n-1 || y1== m-1 || x2 == 0 || y2 == 0 || x2 == n-1 || y2 == m-1){
            cout<<3<<endl;
        }
        else
            cout<<4<<endl;

        
    }
    return 0;
}