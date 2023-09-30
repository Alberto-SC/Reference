#include <bits/stdc++.h>
using namespace std;
const int N = 10000000;
typedef long long int lli;
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
map<int,int> getfactors(int x){
    map<int,int> m;
    while(x%2 == 0){
        x/=2;
        m[2]++;
    }
    for(int i = 3;i*i<=x;i+=2){
        while(x%i==0){
            m[i]++;
            x/=i;
        }
    }
    if(x >1)m[x]++;
    return m;
}
lli lcm(lli a,lli b){
    return b*(a/__gcd(a,b));
}
int main(){
    int n;
    cin>>n;
    criba();
    vector<int> nums(n);    
    for(auto &c:nums)cin>>c;
    if(n == 1)return cout<<nums[0]<<endl,0;
    vector<map<int,int>> facts(n);
    for(int i = 0;i<n;i++){
        facts[i] = getfactors(nums[i]);
    }
    vector<int> b(230007,0);
    for(int i = 0;i<n;i++){
        for(auto c:facts[i]){
            b[c.first]++;
        }
    }

    lli ans =1;
    for(int i =0;i<20000;i++){
        if(b[primes[i]]<n-1)continue;
        int mn = 1000,mn2 = 1000,cont = 0;
        for(int j = 0;j<n;j++){
            if(facts[j].find(primes[i])!= facts[j].end()){
                
                mn = min(mn,facts[j][primes[i]]);
            }
        }
        int contmn = 0;
        for(int j = 0;j<n;j++)
            if(facts[j].find(primes[i])!= facts[j].end() && facts[j][primes[i]] == mn)
                contmn++;

        // cout<<primes[i]<<" "<<mn<<" "<<contmn<<" "<<cont<<endl;
        if(contmn ==1 && b[primes[i]] == n){
            for(int j = 0;j<n;j++){
                if(facts[j].find(primes[i])!= facts[j].end()){
                    if(facts[j][primes[i]] == mn)continue;
                    mn2 = min(mn2,facts[j][primes[i]]);
                }
            }
            // cout<<mn2<<endl;
            ans*=pow(primes[i],mn2);
        }
        else {
            ans*=pow(primes[i],mn);
        }
    }
    cout<<ans<<endl;
    return 0;
}