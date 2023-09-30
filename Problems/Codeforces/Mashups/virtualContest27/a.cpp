#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n,k;
    while(t--){
        cin>>n>>k;
        int diff = abs((k-1)-n);
        if(diff<n)
            cout<<(n-diff)/2<<endl;
        else 
            cout<<0<<endl;
    }
    return 0;
}  
