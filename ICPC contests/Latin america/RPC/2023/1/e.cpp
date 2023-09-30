#include <bits/stdc++.h>

#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n';

using namespace std;

const int inf = -1e9;
struct STmax{
    int n;
    vector<int> st;
    STmax(int n):n(n){
        st.resize(2*n,inf);
    }
	inline void update(int x, int val) {
		x += n;
		st[x] = val;
		for (; x >>=1 ; st[x] = max(st[x<<1], st[x<<1|1]));
	}
	inline int query(int l, int r) {
		int ans = inf;
        if(r<l)return 0;
		for (l += n, r += n; l <= r; l = (l + 1) / 2, r = (r - 1) / 2) {
			if (l & 1) ans = max(ans, st[l]);
			if (~r & 1) ans = max(ans, st[r]);
		}
		return ans;
	}
};

signed main(){__
    int T,n,m;
    cin>>n;
    vector<int> nums(n);
    for(auto &c:nums)cin>>c;

    STmax st(n);
    for(int i = 0;i<n;i++){
        st.update(i,nums[i]);
    }
    int N = 1000007;
    map<int,vector<int>> pos;

    for(int i = 0;i<n;i++)
        pos[nums[i]].push_back(i);

    int ans = 0;
    for(auto c:pos){
        for(int j = 1;j<c.second.size();j++){
            int l = c.second[j-1];
            int r = c.second[j];
            int len = r-l;
            if(len==1)continue;
            int mx = st.query(l+1,r-1);
            if(mx<c.first)ans+=len-1;
        }
    } 
    cout<<ans<<endl;
    return 0;
}

