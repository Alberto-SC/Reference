#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

const int N = 20000007;

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

signed main(){__
	int t= 1,n,c,d,x;
    cin>>t;
    criba();
    vector<int> cont(N);
    for (int i = 2;i<N;i++) {
        int j = i/lp[i];
        cont[i] = cont[j] + (lp[i] != lp[j]);
    }
    while(t--){
        cin>>c>>d>>x;
        int ans = 0;
        for(int i = 1;i*i<=x;i++){
            if(x%i==0){ 
                if(((x/i)+d)%c == 0) 
                    ans += 1<<cont[((x/i)+d)/c];
                if (i*i == x)continue;
                if ((i+d)%c==0)
                    ans += 1<<cont[(i+d)/c];    
            }
        } 
        cout<<ans<<endl;
    }
    return 0;
}  

