#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

const int N = 1000007;
int lp[N+1];
vector<int> primes;
void criba(){
    for (int i=2; i<=N; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            primes.push_back (i);
        }
        for (int j=0; j<(int)primes.size() && primes[j]<=lp[i] && i*primes[j]<=N; ++j){
            lp[i * primes[j]] = primes[j];
            if(i%primes[j]==0)break;
        }
    }
}
signed main(){__
    int T = 1,n,e;
    cin>>T;
    criba();
    while(T--){
        cin>>n>>e;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        vector<int> v[e];
        for(int i = 0;i<n;i++){
            v[i%e].push_back(nums[i]==1);
        }
        int ans = 0;
        for(int x =0;x<e;x++){
            int N = v[x].size();
            vector<int> z;
            for(int i = N-1;i>=0;i--){
                if(v[x][i] == 0)z.push_back(i);
            }

            for(int i = 0;i<N;i++){
                if(v[x][i]== 0){
                    z.pop_back();
                    int nxt = z.size()?z.back():N;
                    int id = (e*i)+x;
                    if(lp[nums[id]] == nums[id])
                        ans+=nxt-i-1;
                }
                else{
                    int M = z.size();
                    if(M==0)continue;
                    int l = z[M-1];
                    int id = (e*l)+x;
                    int r = M>=2?z[M-2]:N;
                    if(lp[nums[id]] == nums[id])
                        ans+=r-l;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}