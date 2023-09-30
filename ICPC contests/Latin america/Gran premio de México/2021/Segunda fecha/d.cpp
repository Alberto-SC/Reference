#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n,C,R,S;
    cin>>t;
    while(t--){
        cin>>C>>R>>S;
        int c = ceil((C+R)/(S*1.0));
        int mn = c-min(R,c);
        int mx = c-ceil(R/(S*1.0));
        cout<<mx<<" "<<mn<<endl;
    }
    return 0;
}  
