#include <bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'


typedef unsigned long long int  ull;
typedef long long int lli;

vector<lli> ps;
    
int CONST = 20;
lli M = (1<<CONST)-1;

lli modMult(lli a, lli b, lli mod) {
    lli a1 = (M&a);
    lli a2 = ((a>>CONST)&M);
    lli ret = a2 * b;
    ret %= mod;
    ret <<= CONST;
    ret += a1 * b;
    ret %= mod;
    return ret;
}

lli modExpo(lli base, lli exp, lli mod) {
    if (exp == 0) return 1;
    if (exp == 1) return base % mod;
    lli tmp = modExpo(base, exp>>1, mod);
    tmp = modMult(tmp, tmp, mod);
    if (exp&1)
        tmp = modMult(tmp, base, mod);
    return tmp;
}

int isprime(lli x) {
    if (x == 2) return 1;
    if (!(x&1)) return 0;
    for (int i = 1; ps[i] * ps[i]  <= x && i < 4; i++) {
        if (!(x % ps[i])) return 0;
    }
    for (int i = 1; ps[i] * ps[i]  <= x; i++) {
        if (!(x % ps[i])) return 0;
        if (i < 4) {
            lli a = ps[i];
            if (modExpo(a, x, x) != a) return 0;
        }
        //*/
    }
    return 1;
}

lli solve2(int x) {
    lli ret = x;
    lli ret2 = 0;
    while (x >= 10) {
        ret *= 10;
        x /= 10;
        ret2 *= 10;
        ret2 += (x % 10);
    }
    ret += ret2;
    return ret;
}


lli solve(lli x, lli y) {
    int i = 2;
    lli j = solve2(i);
    lli ans = 0;
    cout<<j<<endl;
    while (j < x) {
        i++;
        j = solve2(i);
        cout<<j<<endl;
    }
    while (j <= y) {
        ans += isprime(j);
        i++;
        j = solve2(i);
    }
    return ans + (x <= 11 && y >= 11);
}
const int N = 1000000;
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
#define MAX 400010

int main(){__
    lli l,r;
    // criba();
 vector<int> isps;
    for (int i = 0; i < MAX; i++)
        isps.push_back(1);
    isps[0] = isps[1] = 0;
    for (int j = 2; j < MAX; j++)
        if (isps[j])
            for (int k = (j<<1); k < MAX; k+=j)
                isps[k] = 0;
    
    for (int i = 0; i < MAX; i++)
        if (isps[i])
            ps.push_back(i);
    cin>>l>>r;
    cout << solve(l,r) << endl;
    return 0;
}