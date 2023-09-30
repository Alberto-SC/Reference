#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

int n,m;
int maxn = 300007;
vector<int> bit(maxn);
int sum(int idx) {
    int ret = 0;
    for (++idx; idx > 0; idx -= idx & -idx)ret += bit[idx];
    return ret;
}

int sum(int l, int r) {
    return sum(r) - sum(l - 1);
}

void add(int idx, int delta) {
    for (++idx; idx < maxn; idx += idx & -idx) bit[idx] += delta;
}

signed main(){__
	int t= 1,n;
    cin>>n;
    vector<int> nums(n);
    for(auto &c:nums)cin>>c;
    vector<int> u(nums);
    sort(u.begin(),u.end());
    vector<int> pos(n);
    for(int i = 0;i<n;i++){
        nums[i] =lower_bound(u.begin(),u.end(),nums[i])-u.begin();
        pos[nums[i]] = i;
        add(i,1);
    }
    int ans = 0;
    for(int i = 0;i<n;i++){
        int p = pos[i];
        add(p,-1);
        int l = sum(p);
        int r = n-i-1-l;
        ans+=min(l,r);
    }
    cout<<ans<<endl;

}  
