#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

const int inf = 1e15;
struct STmin{
    int n;
    vector<int> st;
    STmin(int n):n(n){
        st.resize(2*n,inf);
    }
	inline void update(int x, int val) {
		x += n;
		st[x] = val;
		for (; x >>=1 ; st[x] = min(st[x<<1], st[x<<1|1]));
	}
	inline int query(int l, int r) {
		int ans = inf;
        if(r<l)return 0;
		for (l += n, r += n; l <= r; l = (l + 1) / 2, r = (r - 1) / 2) {
			if (l & 1) ans = min(ans, st[l]);
			if (~r & 1) ans = min(ans, st[r]);
		}
		return ans;
	}
};

signed main(){__
    int T = 1,n;
    cin>>T;
    while(T--){
        cin>>n;
        vector<int> a(n-1);
        vector<int> b(n);
        vector<int> L(n);
        vector<int> R(n);
        for(auto &c:a)cin>>c;
        for(auto &c:b)cin>>c;
        for(auto &c:L)cin>>c,c--;
        for(auto &c:R)cin>>c,c--;

        vector<int> ans(n);
        STmin st(n);
        st.update(0,b[0]);
        for(int i = 1;i<n;i++){ 
            int res = ans[i-1]+a[i-1];
            int mn = 1e15;
            if(L[i]<i)
                mn = st.query(L[i],min(i-1,R[i]));
        
            res = min(res,mn);
            ans[i] = res;
            st.update(i,res+b[i]);
        }
        for(auto c:ans)cout<<c<<" ";
        cout<<endl;
    }
    return 0;
}