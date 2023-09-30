#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n;
    cin>>t;
    while(t--){
        cin>>n;
        while(1){
            int aux = n, s = 0;
            while(aux){
                s+=aux%10;
                aux/=10;
            }
            if(gcd(n,s)>1)break;
            n++;
        }
        cout<<n<<endl;
    }
    return 0;
}  
