#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
const int N = 1000000;
int lp[N+1];
vector<int> pm;
void criba(){
    for (int i=2; i<=N; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            pm.push_back (i);
        }
        for (int j=0; j<(int)pm.size() && pm[j]<=lp[i] && i*pm[j]<=N; ++j)
            lp[i * pm[j]] = pm[j];
    }
}
map<int,int> fact;

void factorize(int n){
    while(n>1){
        fact[lp[n]]++;
        n/=lp[n];
    }
}

signed main(){
	int t= 1,m;
    criba();
    int c = 1;
    cin>>t;
    while(t--){
        cin>>m;
        vector<int> nums(m);
        vector<int> primes(m);
        int x = 0;
        for(int i = 0;i<m;i++){
            cin>>primes[i]>>nums[i];
            x+= nums[i]*primes[i];
        }
        int ans = 0;
        // cout<<x<<endl;
        for(int i = x;i>=0;i--){
            fact.clear();
            factorize(i);
            int sum = x;
            bool flag = true;
            for(auto p:fact){
                int idx = lower_bound(primes.begin(),primes.end(),p.first)-primes.begin();
                if(idx==(int) primes.size()){
                    flag = false;
                    break;
                }
                if(primes[idx]!= p.first){
                    flag = false;
                    break;
                }
                if(nums[idx]<p.second){
                    flag = false;
                    break;
                }
                sum-= p.second*p.first;
            }
            if(!flag)continue;
            if(sum == i){
                ans = i;
                break;
            }
        }
        cout<<"Case #"<<c<<": "<<ans<<endl;
        c++;
    }
    return 0;
}  
