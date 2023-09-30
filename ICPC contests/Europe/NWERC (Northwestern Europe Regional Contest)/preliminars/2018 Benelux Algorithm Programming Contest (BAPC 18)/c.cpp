#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
	lli t= 1,n;
    while(t--){
        cin>>n;
        lli mn  = 1e15;
        for(lli i = 1;i<=n;i++){
            for(lli j = 1;i*j<=n;j++){
                for(int k = 1;i*j*k<=n;k++){
                    if(i*j*k==n){
                        // cout<<i<<" "<<j<<" "<<k<<endl;
                        mn = min(mn,(i*j*2)+(j*k*2)+(k*i*2));
                    }
                }
            }
        }
        cout<<mn<<endl;
    }
    return 0;
}  

