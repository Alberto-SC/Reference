#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
const int N = 10000000;
int lp[N+1];
vector<int> primes;
void criba(){
    for (int i=2; i<=N; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            primes.push_back (i);
        }
        for (int j=0; j<(int)primes.size() && primes[j]<=lp[i] && i*primes[j]<=N; ++j)
            lp[i * primes[j]] = primes[j];
    }
}
int main(){__
    criba();
	int t= 1,n;
    cin>>n;
    for(int i = 2;i<=n-2;i++){
        if(lp[i]!= i&& lp[n-i]!= n-i){
            cout<<i<<" "<<n-i<<endl;
            break;
        }
    }
    return 0;
}  

