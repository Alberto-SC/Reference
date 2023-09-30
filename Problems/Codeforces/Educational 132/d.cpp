#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

const int inf = -1e18;
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
    int T = 1,n,m;
    while(T--){
        cin>>n>>m;
        vector<int> nums(m);
        for(auto &c:nums)cin>>c;
        STmax st(m+1);
        for(int i = 1;i<=m;i++){
            st.update(i,nums[i-1]);
        }
        int q;
        cin>>q;
        while(q--){
            int x1,y1,x2,y2,k;
            cin>>x1>>y1>>x2>>y2>>k;
            if(y1>y2){
                swap(x1,x2);
                swap(y1,y2);
            }

            int Ax = x2-x1;
            int Ay = abs(y2-y1);
            if(Ax%k || Ay%k){
                cout<<"NO"<<endl;
                continue;
            }

            int mx = st.query(y1,y2);
            int mdx = x1%k;
            int mdy = mx%k;
            int need = 0;
            if(mdx == mdy)need = k;
            else if(mdy>mdx)
                need = k-(mdy-mdx);
            else 
                need = mdx-mdy;
            

            if(mx+need<=n)cout<<"YES"<<endl;
            else cout<<"NO"<<endl;


        }
    }
    return 0;
}