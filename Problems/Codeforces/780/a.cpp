#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);


signed main(){__
	int t= 1,n,k,a,b;
    cin>>t;
    while(t--){
        cin>>a>>b;
        if(a==0)cout<<1<<endl;
        else cout<<(b*2)+a+1<<endl;
    }
    return 0;
}  
