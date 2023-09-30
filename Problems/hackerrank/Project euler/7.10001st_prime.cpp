#include <bits/stdc++.h>
using namespace std;

const int N = 10000000;
vector<int> lp(N+1);
vector<int> primes;

void criba(){
    for(int i = 2;i<=N;i++){
        if(lp[i]== 0){
            lp[i] = i;
            primes.push_back(i);
        }
        for(int j = 0;j<primes.size() && primes[j]<=lp[i] && i*primes[j]<=N ;j++)
            lp[i*primes[j]] = primes[j];

    }
}

int main(){
    int t,n;
    cin>>t;
    criba();
    while(t--){
        cin>>n;
        cout<<primes[n-1]<<endl;
    }
    return 0;
}
