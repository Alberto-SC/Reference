#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
const int N = 10000000;

int lp[N+1];
vector<int> primes;
map<lli,lli> trial_division4(lli n) {
    map<lli,lli> fact;
    for (lli d : primes) {
        if (d * d > n)
            break;
        while (n % d == 0) {
            fact[d]++;
            n /= d;
        }
    }
    if(n>1)fact[n]++;
    return fact;
}
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
class  DevuAndEqualizingLCM{
public:

    int minimumOperationsNeeded(vector<lli> A, vector<lli> B){ 
        criba();
        // for(int i = 0;i<20;i++)cout<<primes[i]<<" ";
        // cout<<endl;
        map<lli,lli> fact[A.size()];
        for(int i = 0;i<A.size();i++){
            fact[i] = trial_division4(A[i]);
        }
        map<lli,lli> lcm;
        vector<lli> b(100);
        for(int i = 0;i<A.size();i++){
            for(auto c:fact[i]){
                b[c.first] = max(b[c.first],c.second);
            }
            // cout<<endl;
        }
        for(int i = 0;i<100;i++){
            if(b[i]!= 0)lcm[i]= b[i];
        }

        // for(auto c:lcm){
            // cout<<c.first<<" "<<c.second<<endl;
        // }
        map<lli,lli> factb[B.size()];
        for(int i = 0;i<B.size();i++){
            factb[i] = trial_division4(B[i]);
        }
        int ans = 0;
        for(int i = 0;i<B.size();i++){
            for(auto c:factb[i]){
                if(lcm.count(c.first)){
                    if(c.second>lcm[c.first]){ans++;break;}
                }
                else {ans++;break;}
            }
        }
        return ans;
    }
    
};

int main(){
    int n,m;
    cin>>n>>m;
    vector<lli> a(n);
    vector<lli> b(m);
    for(auto &c:a)cin>>c;
    for(auto &c:b)cin>>c;
    DevuAndEqualizingLCM solve;
    cout<<solve.minimumOperationsNeeded(a,b)<<endl;
    // cout<<solve.minimumOperationsNeeded(a,b)<<endl;
}

