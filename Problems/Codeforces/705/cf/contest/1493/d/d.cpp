#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
const int mod = 1e9+7;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef long long int lli;
const int RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
struct chash { 
	const uint64_t C = lli(4e18 * acos(0)) | 71;
	lli operator()(lli x) const { return __builtin_bswap64(x*C); }
};

vector<gp_hash_table<lli,int,chash>> st;

const int N = 500000;
int lp[N+1];
vector<int> primes;

long long mod_pow(long long a,long long b){
    long long x= 1;
    while(b){
        if(b&1) (x*=a)%=mod;
        (a*=a)%=mod;
        b>>=1;
    }
    return x;
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

gp_hash_table<lli,int,chash> get_factors(int x){
    gp_hash_table<lli,int,chash> fact({},{},{},{},{1<<16});
    while(x>1){
        fact[lp[x]]++;
        x/=lp[x];
    }
    if(x ==1)
        fact[x] = 1;
    return fact;
}

gp_hash_table<lli,int,chash> mergest(gp_hash_table<lli,int,chash>&a ,gp_hash_table<lli,int,chash> &b){
    gp_hash_table<lli,int,chash> ans({},{},{},{},{1<<16});
    if(a.size()==0)return b;
    if(b.size()==0)return a;
    for(auto c:a){
        if(b.count(c.first)){
            ans[c.first] = min(c.second,b[c.first]);
        }
    }
    return ans;
}

gp_hash_table<lli,int,chash> updatemp(gp_hash_table<lli,int,chash>&a,gp_hash_table<lli,int,chash> &b){
    gp_hash_table<lli,int,chash> ans({},{},{},{},{1<<16});
    for(auto c:a)
        ans[c.first]+=c.second;
    for(auto c:b)
        ans[c.first]+=c.second;
    return ans;
}
int n;
inline void update(int x, int val) {
    x += n;
    gp_hash_table<lli,int,chash> mpx = get_factors(val);
    st[x] = updatemp(st[x],mpx);
    for (; x >>=1 ; st[x] = mergest(st[x<<1], st[x<<1|1]));
}

signed main(){__
	int t= 1,idx,x,q;
    criba();
    while(t--){
        cin>>n>>q;
        st.resize(2*n,gp_hash_table<lli,int,chash> h({},{},{},{},{1<<16}));
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        for(int i = 0;i<n;i++)
            update(i,nums[i]);
        for(int i = 0;i<q;i++){
            cin>>idx>>x;
            idx--;
            update(idx,x);
            long long ans = 1;
            for(auto d:st[1]){
                // cout<<d.first<<"->"<<d.second<<endl;
                ans*= mod_pow(d.first,d.second);
                ans%=mod;
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}  
