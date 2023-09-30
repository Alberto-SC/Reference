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
	int t= 1,d;
    criba();
    cin>>t;
    while(t--){
        cin>>d;
        int idx=0,idx2;
        for(int i = 0;i<primes.size();i++){
            if(primes[i]-1>=d){
                idx = i;
                break;
            }
        }  
        for(int i = idx;i<primes.size();i++){
            if(primes[i]-primes[idx]>=d){
                idx2 = i;
                break;
            }
        }
        cout<<primes[idx]*primes[idx2]<<endl;
    }
    return 0;
}  

