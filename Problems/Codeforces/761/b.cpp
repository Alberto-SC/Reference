#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n;
    cin>>t;
    vector<int> primes ={3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61};
    while(t--){
        cin>>n;
        if((n-3)&1)cout<<2<<" "<<n-3<<" "<<1<<endl;
        else{
            for(int i = 0;i<primes.size();i++){
                if((n-(primes[i]+1))%primes[i]){
                    cout<<primes[i]<<" "<<n-(primes[i]+1)<<" "<<1<<endl;
                    break;
                }
            }
        }
    }
    return 0;
}  


