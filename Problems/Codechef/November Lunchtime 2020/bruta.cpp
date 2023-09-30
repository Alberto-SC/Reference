#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
	int t= 1,x,y,n;
    cin>>t;
    while(t--){
        cin>>x>>y>>n;
        int ans = 0;
        for(int i= 0;i<=n;i++){
            if((x^i)<(y^i)){
                ans++;
                bitset<12> b(i);
                // cout<<b<<endl;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}  

