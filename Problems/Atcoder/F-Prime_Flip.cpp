#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

const int N = 10000001;
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
signed main(){__
    int n;
    cin>>n;
    vector<int> nums(n);
    for(auto &c:nums)cin>>c;
    criba();
    int l = (nums.back()-nums[0])+1;
    if(l == 1)return cout<<3<<endl,0;
    if(l%2==0)return cout<<2<<endl,0;
    if(lp[l]==n)return cout<<1<<endl,0;
    bool p2 = false;
    for(int i= 1;i<primes.size();i++){
        if(primes[i]>l)break;
        if(lp[l-primes[i]] == l-primes[i] && l-primes[i]>=3)
            p2 = true;        
    }
    if(p2)cout<<2<<endl;
    else cout<<3<<endl;

    return 0;
}