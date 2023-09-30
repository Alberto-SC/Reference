#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);


const int M = 10000007;
vector<int> primes;
vector<int> lp(M+1);
void criba(){
    for(int i = 2;i<M;i++){
        if(!lp[i]){
            lp[i] = i;
            primes.push_back(i);
        }
        for(int j = 0;j<primes.size() && primes[j]*i<=M && primes[j]<= lp[i];j++)
            lp[primes[j]*i] = primes[j];
    }
}

map<int,int> factorize(int n){
    map<int,int> mp;
    if(n==1)return mp;
    while(lp[n]!=n){
        mp[lp[n]]++;
        n/=lp[n];
    }
    if(n>1)
        mp[n]++;
    return mp;
}

signed main(){__
    int T = 1,n,a,b;
    criba();
    cin>>T;
    while(T--){
        cin>>a>>b;
        map<int,int> mp1 = factorize(a);
        map<int,int> mp2 = factorize(b);
        for(auto c:mp2){
            mp1[c.first]+=c.second;
        }
        cout<<mp1.size()<<endl;
    }
    return 0;
}