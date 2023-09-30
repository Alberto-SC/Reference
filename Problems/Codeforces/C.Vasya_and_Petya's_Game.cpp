#include <bits/stdc++.h>
using namespace std;
const int N = 10000;
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
int main(){
    int n;
    cin>>n;
    criba();
    vector<int> ans;
    for(int i = 0;primes[i]<=n;i++){
        int aux = primes[i];
        int j = 1;
        while(true){int aux2 = pow(aux,j);if(aux2>n)break;ans.push_back(aux2);j++;}
    }
    cout<<ans.size()<<endl;
    for(auto c:ans)cout<<c<<" ";
    return 0;
}