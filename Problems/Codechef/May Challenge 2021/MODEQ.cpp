#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n,m;
    cin>>t;
    while(t--){
        cin>>n>>m;
        int cont = 0;
        int cont2 = 0;
        // for(int i = 1;i<=n;i++){
        //     for(int j = i+1;j<=n;j++){
        //         int lcm = i*j/__gcd(i,j);
        //         int gcd = __gcd(i,j);
        //         if(((m%i)%j) == ((m%j)%i)){
        //             cout<<i<<" "<<j<<" "<<lcm<<" "<<gcd<<" "<<m%lcm<<" "<<m%gcd<<endl;
        //             cont2++;
        //         }
        //         // else{
        //             // if(m%lcm<j)
        //                 // cout<<i<<" "<<j<<" "<<lcm<<" "<<m%lcm<<endl;
        //         // }

        //     }
        // }
        vector<int> M(n+1);
        for(int i = 1;i<=n;i++){
            cont+=M[m%i];
            for(int j = m%i;j<=n;j+=i){
                M[j]++;
            }
        }

        cout<<cont<<endl;
    }
    return 0;
}  
