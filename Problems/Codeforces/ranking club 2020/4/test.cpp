#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
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
int main(){
    criba();
    for(int i = 1;i<1000;i++){
        cout<<"__________________________________"<<endl<<primes[i]<<endl<<endl;
        int cont = 0;
        for(int j = 0;j<100000;j++){
            lli result = primes[i]*j;
            string s = to_string(result);
            string copy = s;
            reverse(s.begin(),s.end());
            if(s == copy)
                cont++;
                // cout<<j<<" "<<s<<endl;
            
        }
        cout<<cont<<endl;
    }
}
