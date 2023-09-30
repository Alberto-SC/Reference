#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

int M;
vector<int> lp(M+1);
vector<int> primes;

void sieve(){
    for(int i = 2;i<=M;i++){
        if(lp[i]== 0){
            lp[i] = i;
            primes.push_back(i);
        } 
        for(int j = 0;i<primes.size() && primes[j]*i <= M && primes[j]<=lp[i];j++){
            lp[primes[j]*i] = primes[j];
        }
   }
}

signed main(){__
    int T = 1,n;

    sieve();
    vector<int> nums(n);
    for(auto &c:nums)cin>>c;
    

    while(T--){
        cin>>n;
        int ans = 1;
        for(int i = 1;i<=n;i++){
            ans*=i;
        }
        cout<<ans<<endl;
    }
    return 0;
}
