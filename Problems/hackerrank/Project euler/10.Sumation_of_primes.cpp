#include <bits/stdc++.h>
using namespace std;
#define int long long
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);

const int N = 10000000;
vector<int> lp(N+1);
vector<int> primes;

void criba(){
    for(int i = 2;i<=N;i++){
        if(lp[i]== 0){
            lp[i] = i;
            primes.push_back(i);
        }
        for(int j = 0;j<primes.size() && primes[j]<=lp[i] && i*primes[j]<=N ;j++)
            lp[i*primes[j]] = primes[j];
    }
}


signed main(){
    int t,n;
    cin>>t;
    criba();
    vector<int> ac(primes.size());
    ac[0] = primes[0];
    for(int i= 1;i<primes.size();i++)
        ac[i] = ac[i-1] + primes[i];
    while(t--){
        cin>>n;
        int idx = upper_bound(primes.begin(),primes.end(),n)-primes.begin();
        if(idx-1<0)cout<<0<<endl;
        else
            cout<<ac[idx-1]<<endl;
    }
    return 0;
}
