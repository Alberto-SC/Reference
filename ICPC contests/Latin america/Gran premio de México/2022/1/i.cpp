#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n;
    while(t--){
        cin>>n;
        int x  = n;
        int ans = 0;
        while(n){
            int y = n%10;
            if(y && x%y ==0)ans++;
            n/=10;
        }
        cout<<ans<<endl;
    }
    return 0;
} 