#include <bits/stdc++.h>
using namespace std; 
int main(){
    int n,m,k,x,y;
    int ESD = 0,ESI = 0,EID = 0,EII = 0;
    cin>>n>>m>>k;
    for(int i = 0;i<k;i++){
        cin>>x>>y;
        if(x>1 && x<n || y>1 && y<m)continue;
        if(x == 1 && y == 1)ESI = 1;
        if(x == 1 && y == m)ESD = 1;
        if(x == n && y == 1)EII = 1;
        if(x == n && y == m)EID = 1;
    }
    if(n== 1 && m == 1){if(EID == 1)cout<<0<<endl;else cout<<1<<endl;}
    else if(n == 1)cout<<2-ESI-ESD<<endl;
    else if(m == 1)cout<<2-ESI-EII<<endl;
    else cout<<4-ESD-ESI-EID-EII<<endl;
    return 0;
}