#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n,m,k;
    cin>>t;
    while(t--){
        cin>>n>>m>>k;
        k--;
        int y = k/n;
        int x = k%n;
        cout<<(x*m)+y+1<<endl;
    }
    return 0;
}  
