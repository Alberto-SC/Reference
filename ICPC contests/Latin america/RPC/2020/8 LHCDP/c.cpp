#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

const lli mod = 1000000007;
const lli N = 10000000;
lli lp[N+1];
vector<lli> primes;
void criba(){
    for(lli i = 2;i<=N;i++){
        if(lp[i] == 0){
            lp[i] = i;
            primes.push_back(i);
        }
        for(lli j = 0;j<(lli)primes.size() && primes[j]<=lp[i] && i*primes[j]<=N;j++)
            lp[i*primes[j]] = primes[j];
    }
}

lli countDivisors(lli n){
    lli ans = 1;
    for(lli i = 0;i<primes.size();i++){
        if(n ==1)break;
        lli p = primes[i];
        if(n%p== 0){
            lli num = 0;
            while(n%p == 0){
                n/=p;
                ++num;
            }
            ans*=num+1;
        }
    }
    return ans;
}

const lli maxn = 5007;
lli bc[maxn][maxn];
lli binomial(lli n,lli m){
    for(lli i = 0;i<=n;i++)bc[i][0] = 1;
    for(lli j = 0;j<=n;j++)bc[j][j] = 1;
    for(lli i = 1;i<=n;i++)
        for(lli j = 1;j<i;j++)
            bc[i][j] = (bc[i-1][j-1]+bc[i-1][j])%mod;
}
lli nextInt() {
    lli x = 0, p = 1;
    char c;
    do {
        c = getchar();
    } while (c <= 32);
    if (c == '-') {
        p = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x * p;
}

int main(){
    lli t,n,k;
    // cin>>t;
    t = nextInt();
    criba();
    binomial(maxn-1,maxn-1);
    vector<int> divs(maxn);
    for(int i = 1;i<maxn;i++)
        divs[i] =countDivisors(i); 
    
    while(t--){
        n = nextInt();
        k = nextInt();
        lli graphs= 1;
        lli ans =0;
        for(lli i = 1;i<=n;i++){
            lli div = divs[i];
            div--;
            // cout<<div<<endl;
            if(div>k){
                graphs*=bc[div][k];
                graphs%=mod;
                ans+=k;
            }
            else{
                ans+=div;
            }
        }
        printf("%lld %lld\n",ans,graphs);
        // cout<<ans<<" "<<graphs<<endl;
    }
    return 0;
}