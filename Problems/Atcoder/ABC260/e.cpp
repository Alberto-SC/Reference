#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

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
    int T = 1,n,m;
    while(T--){
        cin>>n>>m;
        vector<vector<int>> v(n,vector<int> (3));
        vector<int> a[m+1];
        STmax st(n);
        vector<int> Nxt(n,1);
        for(int i= 0;i<n;i++){
            cin>>v[i][0];
            cin>>v[i][1];
            if(v[i][0]>v[i][1])swap(v[i][0],v[i][1]);
            a[v[i][0]].push_back(i);
            a[v[i][1]].push_back(i);
            v[i][2] = -inf;
            st.update(i,v[i][0]);
        }
        int ans = 0;

        vector<int> ac(m+3);

        for(int i = 1;i<=m;i++){
            int nxt = st.query(0,n-1);
            int l = (nxt-i)+1;
            int r = (m-i)+1;
            if(l<=r){
                ac[l]++;
                ac[r+1]--;
            }
            for(auto d:a[i]){
                st.update(d,v[d][Nxt[d]]);
                Nxt[d]++;
            }
        }
        for(int i = 1;i<=m;i++){
            ac[i]+=ac[i-1];
            cout<<ac[i]<<" ";
        }
        cout<<endl;
        
    }
    return 0;
}
