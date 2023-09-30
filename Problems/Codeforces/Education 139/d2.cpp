#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);


const int N = 10000007;
int lp[N+1];
vector<int> primes;
void criba(){
    for (int i=2; i<=N; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            primes.push_back (i);
        }
        for (int j=0; j<(int)primes.size() && primes[j]<=lp[i] && i*primes[j]<=N; ++j){
            lp[i * primes[j]] = primes[j];
            if(i%primes[j]==0)break;
        }
    }
}

signed main(){__
    int T = 1,n,x,y;
    cin>>T;
    criba();
    while(T--){
        cin>>x>>y;
        int diff = y-x;
        if(diff ==1){
            cout<<-1<<endl;
            continue;
        }
        if(__gcd(x,y)!=1){
            cout<<0<<endl;
            continue;
        }
        int ans2 = 1e9;
        while(lp[diff]>1){
            int md = x%lp[diff];
            ans2 = min(ans2,lp[diff]-md);
            diff/=lp[diff];
        }
        cout<<ans2<<endl;
    }
    return 0;
}