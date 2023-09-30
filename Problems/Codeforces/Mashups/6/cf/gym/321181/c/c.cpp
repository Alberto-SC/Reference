#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

#include <ext/pb_ds/assoc_container.hpp>
#include <bits/extc++.h> /** keep-include */
using namespace __gnu_pbds;
const int RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();

typedef long long int lli;
// For CodeForces, or other places where hacking might be a problem:
struct chash { // To use most bits rather than just the lowest ones:
	const uint64_t C = lli(4e18 * acos(0)) | 71; // large odd number
	lli operator()(lli x) const { return __builtin_bswap64((x^RANDOM)*C); }
};
__gnu_pbds::gp_hash_table<lli, int, chash> h({},{},{},{}, {1 << 16});


const int maxn = 30007;
int P[maxn];
__gnu_pbds::gp_hash_table<lli, int, chash> DP[maxn];
int solve(int idx,int prev){
    if(idx>30001)
        return 0;
    if(DP[idx].find(prev)!= DP[idx].end())return DP[idx][prev];
    int l = idx-prev;
    if(l>1)
        DP[idx][prev] = max({solve(idx+l,idx),solve(idx+l+1,idx),solve(idx+l-1,idx)})+P[idx];
    else if(l==1)
        DP[idx][prev] = max({solve(idx+l,idx),solve(idx+l+1,idx)})+P[idx];
 
    return DP[idx][prev];
}
signed main(){__
	int t= 1,n,d;
    while(t--){
        cin>>n>>d;
        for(int i = 0;i<n;i++){
            int x;
            cin>>x;
            P[x]++;
        }
        cout<<solve(d,0)<<endl;
        int mx = 0;
        for(int i = 0;i<maxn;i++){
            mx = max(mx,(int)DP[i].size());
            // cout<<DP[i].size()<<" ";
        }
        cout<<mx<<endl;
    }
    return 0;
}  
