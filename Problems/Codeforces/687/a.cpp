#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
	int t= 1,n,m,r,c;
    cin>>t;
    while(t--){
        cin>>n>>m>>r>>c;
        cout<<max({(n-r)+(m-c),(r-1)+(c-1),(r-1)+(m-c),(n-r)+(c-1)})<<endl;
    }
    return 0;
}  

