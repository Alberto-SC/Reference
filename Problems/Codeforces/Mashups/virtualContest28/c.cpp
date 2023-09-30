#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
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

map<int,int> fact;
void factorize(int n){
    while(n>1){
        fact[lp[n]]++;
        n/=lp[n];
    }
}
signed main(){__
	int t= 1,n;
    criba();
    while(t--){
        cin>>n;
        fact.clear();
        factorize(n);
        int mx = 0,mn = 1e9;
        if(n==1){
            cout<<1<<" "<<0<<endl;
            continue;
        }
        int res = 1;
        for(auto c:fact){
            mx = max(mx,c.second);
            mn = min(mn,c.second);
            res*=c.first;
        }
        if(mn ==mx &&mn ==1){
            cout<<n<<" "<<0<<endl;
            continue;
        }
        int cont= 0;
        while(1){
            if((1<<cont)>=mx){
                break;
            }
            cont++;
        }
        mx = 1<<cont;
        bool flag= false;
        for(auto c:fact){
            if(c.second<mx)
                flag = true;
        }
        int ans = flag+cont;

        cout<<res<<" "<<ans<<endl;
    }
    return 0;
}  
