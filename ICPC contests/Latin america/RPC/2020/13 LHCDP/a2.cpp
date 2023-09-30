#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

const int lim = 1000007;
int lp[lim+1];
vector<int> primes;
void criba(){
    for (int i=2; i<=lim; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            primes.push_back (i);
        }
        for (int j=0; j<(int)primes.size() && primes[j]<=lp[i] && i*primes[j]<=lim; ++j)
            lp[i * primes[j]] = primes[j];
    }
}

int mod(int x , int m){
    while(x<0)
        x+=m;
    if(x==0) return 1;
    if(x==m) return m;
    if(x>m) return mod(x%m,m);
    return x%m;
}


int main(){
    criba();
    bool vuelta=false;
    ll N,T,s,p,c;
    cin>>N>>T;
    cin>>s>>p>>c;
    int totprimes = upper_bound(primes.begin(), primes.end(), N)-primes.begin();
    if(s-T<=0) vuelta=true;
    ll newS = mod(s-T,N);
    int primesIni = (upper_bound(primes.begin(),primes.end(),s)-primes.begin());
    int primesRest = totprimes - (upper_bound(primes.begin(),primes.end(),newS-1)-primes.begin());
    int contPrimes= totprimes*floor((T-1)/N)+((vuelta)?primesRest:0)+primesIni;
    // cout<<totprimes<< " "<<primesIni<<" "<<primesRest<<" "<<contPrimes<<endl;
    int noPrimes = T-contPrimes;
    ll newP=  mod(p-contPrimes,N);
    ll newC=  mod(c+noPrimes,N);
    cout<<newS<<" "<<newP<<" "<<newC<<"\n";

    return 0;
}
