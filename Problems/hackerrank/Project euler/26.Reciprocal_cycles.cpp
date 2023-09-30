#include <bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
const int N = 1000000;
vector<int> lp(N+1);
vector<int> primes;
vector<bool> isPrime(N+1);

int solve(int a, int b, int m) {
    a %= m, b %= m;
    int k = 1, add = 0, g;
    while ((g = __gcd(a, m)) > 1) {
        if (b == k)
            return add;
        if (b % g)
            return -1;
        b /= g, m /= g, ++add;
        k = (k * 1ll * a / g) % m;
    }

    int n = sqrt(m) + 1;
    int an = 1;
    for (int i = 0; i < n; ++i)
        an = (an * 1ll * a) % m;

    unordered_map<int, int> vals;
    for (int q = 0, cur = b; q <= n; ++q) {
        vals[cur] = q;
        cur = (cur * 1ll * a) % m;
    }

    for (int p = 1, cur = k; p <= n; ++p) {
        cur = (cur * 1ll * an) % m;
        if (vals.count(cur)) {
            int ans = n * p - vals[cur] + add;
            return ans;
        }
    }
    return -1;
}

void criba(){
    for(int i = 2;i<=N;i++){
        if(lp[i]== 0)
            lp[i] =i,isPrime[i] = true,primes.push_back(i);
        for(int j = 0;j<primes.size() && primes[j]<=lp[i] && i*primes[j]<=N;j++)
            lp[i*primes[j]] = primes[j];
    }
}

int main(){__
    int t,n;
    cin>>t;
    criba();
    cout<<solve(10,1,35)<<endl;
    while(t--){
        cin>>n;
        for(int i = n-1;i>=0;i--){
            if(isPrime[i]){
                cout<<i<<endl;
                break;
            }
        }
    }
    return 0;
}
