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
        for (int j=0; j<(int)primes.size() && primes[j]<=lp[i] && i*primes[j]<=N; ++j){
            lp[i * primes[j]] = primes[j];
            if(i%primes[j]==0)break;
        }
    }
}

map<int,int> factorize(int n){
    map<int,int> f;
    for(auto c:primes){
        if(c*c>n)break;
        while(n%c ==0){
            f[c]++;
            n/=c;
        }
    }
    if(n>1)f[n]++;
    return f;
}

signed main(){__
    int T = 1,n,a,b,k;
    criba();
    cin>>T;
    while(T--){
        cin>>a>>b>>k;
        map<int,int> f1 = factorize(a);
        map<int,int> f2 = factorize(b);
        int mx = 0;
        for(auto c:f1){
            mx+=c.second;
        }
        for(auto c:f2){
            mx+=c.second;
        }
        int mn = 1;
        int cm = 0,cmx = 0;
        for(auto c:f1){
            if(c.second<f2[c.first])cm++;
            else if(c.second>f2[c.first])cmx++;
        }
        for(auto c:f2){
            if(f1[c.first]<c.second)cm++;
            else if(f1[c.first]>c.second)cmx++;
        }

        if(k>mx)cout<<"NO"<<endl;
        else if(k==1 && ((cm && cmx) || (a==b)))cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
    return 0;
}