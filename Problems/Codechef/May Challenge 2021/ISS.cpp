#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
// #define int long long 
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

int cont =0 ;
int divs[2000000][109];
int contDivs[2000000];
void generateDivisors(int curIndex, int curDivisor,vector<pair<int,int>>& arr,int who){
    if (curIndex == arr.size()) {
        divs[who][cont] = curDivisor;
        cont++;
        contDivs[who]++;
        return;
    }  
    for (int i = 0; i <= arr[curIndex].second; ++i) {
        generateDivisors(curIndex + 1, curDivisor, arr,who);
        curDivisor *= arr[curIndex].first;
    }
}

map<int,int> factorize(int n){
    map<int,int> fact;
    while(n>1){
        fact[lp[n]]++;
        n/=lp[n];
    }
    return fact;
}


vector<int> Phi; 
void phiSieve(int n){ 
    Phi.resize(n + 1); 
    iota(Phi.begin(),Phi.end(),0);
    for(int i = 2; i <= n; ++i) 
        if(Phi[i] == i) 
            for(int j = i; j <= n; j += i) 
                Phi[j] -= Phi[j] / i; 
}

const int maxn = 4000002;
signed main(){__
	int t= 1,k;
    phiSieve(maxn);
    vector<int> ans(maxn);
    vector<int> res;
    res.push_back(0);
    for(int i = 1;i<maxn;i++){
        ans[i]+=i-1;
        for(int j = 2*i;j<maxn;j+=i)
            ans[j]+=i*((1+Phi[j/i])>>1);
        // if((i-1)%4==0 && i>1)res.push_back(ans[i]);
    }
    cin>>t;
    while(t--){
        cin>>k;
        cout<<ans[(k*4)+1]<<endl;
    }
    return 0;
}  