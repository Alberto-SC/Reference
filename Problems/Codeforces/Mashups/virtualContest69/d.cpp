#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n,x,y,k;
    cin>>t;
    while(t--){
        cin>>x>>y>>k;
        if(x<y)swap(x,y);
        if((x&1) != (y&1))x--,k--;
        else if((x&1) != (k&1))k-=2,x--;
        if(k<x)cout<<-1<<endl;
        else cout<<k<<endl;
    }
    return 0;
}  
