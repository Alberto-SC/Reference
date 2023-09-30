#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define x first
#define y second
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
map<int,int> fact;
void factorize(int n) {
    while(n>1){
        fact[lp[n]]++;
        n/=lp[n];
    }
}

int main(){
	int t= 1,n;
    criba();
    while(t--){
        cin>>n;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        vector<int> ans1(n);
        vector<int> ans2(n);
        for(int i = 0;i<n;i++){
            fact.clear();
            factorize(nums[i]);
            if(fact.size()== 1){
                ans1[i] = -1;
                ans2[i] = -1;
            }
            else{
                int fr = fact.begin()->first;
                fact.erase(fact.begin());
                int sc = 1;
                for(auto c:fact){
                    sc*=c.first;
                }
                ans1[i] = fr;
                ans2[i] = sc;
            }
        }
        for(auto c:ans1)cout<<c<<" ";
        cout<<endl;
        for(auto c:ans2)cout<<c<<" ";
        cout<<endl;
    }
    return 0;
}  

