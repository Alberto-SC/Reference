#include <bits/stdc++.h>
using namespace std;
const int N = 35;
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
    int t,n;
    cin>>t;
    criba();
    while(t--){ 
        cin>>n;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        vector<int> res[11];
        for(int i = 0;i<n;i++)
            for(int j =0;j<primes.size();j++)
                if(nums[i]%primes[j] == 0){res[j].push_back(i);break;}
        int ans = 0;        
        for(int i = 0;i<11;i++){
            if(res[i].size()){
                ans++;
                for(auto c:res[i])
                    nums[c] = ans;
            }
        }     
        cout<<ans<<endl;
        for(auto c:nums)cout<<c<<" ";    
        cout<<endl;
    }
    return 0;
}