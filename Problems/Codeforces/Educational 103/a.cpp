#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
	int t= 1,n,k;
    cin>>t;
    while(t--){
        cin>>n>>k;
        if(n>k){
            int aux = n/k;
            if(n%k)
                aux++;
            k = aux*k;
        }
        int ans = k/n;
        if(k%n)ans++;
        cout<<ans<<endl;
    }
    return 0;
}  

