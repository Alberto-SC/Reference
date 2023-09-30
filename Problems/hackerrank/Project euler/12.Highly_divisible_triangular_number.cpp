#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);

const int N = 10000000;
vector<int> lp(N+1);
vector<int> primes;

void criba(){
    for(int i = 2;i<=N;i++){
        if(lp[i]== 0)
            lp[i] = i,primes.push_back(i);
        for(int j = 0;j<primes.size() && primes[j]<=lp[i] && i*primes[j]<=N;j++)
            lp[i*primes[j]] = primes[j];
    }
}

int numDivisors(int n){
    map<int,int> fact;
    int x = n,y = n+1;
    while(lp[x]!=x){
        fact[lp[x]]++;
        x/=lp[x];
    }
    while(lp[y]!=y){
        fact[lp[y]]++;
        y/=lp[y];
    }
    fact[x]++;
    fact[y]++;
    fact[2]--;
    int divs = 1;
    for(auto c:fact)
        divs*=c.second+1;
    
    return divs;
}

signed main(){__
    int t,n;
    cin>>t;
    criba();
    while(t--){
        cin>>n;
        if(n==1){
            cout<<3<<endl;
            continue;
        }
        for(int i= 2;i<=1000000;i++){
            if(numDivisors(i)>n){
                cout<<(i*(i+1))/2<<endl;
                break;
            }
        }
    }
}
