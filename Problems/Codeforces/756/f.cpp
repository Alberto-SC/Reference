#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

const int inf = 1e16;
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
    int T = 1,n,k;
    cin>>T;
    while(T--){
        cin>>n>>k;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        vector<int> pref(n);
        pref[0] = nums[0];
        STmin st(n);
        st.update(0,pref[0]);
        for(int i = 1;i<n;i++){
            pref[i] = pref[i-1]+nums[i];
            st.update(i,pref[i]);
        }
        int MX = 0,L,R;
        for(int i = 0;i<n;i++){
            int x = k-(i?pref[i-1]:0);
            int mx = -(x+1);
            int l = i-1,r = n;
            while(l+1<r){
                int m  =(l+r)>>1;
                if(st.query(i,m)<=mx)r = m;
                else l = m;
            }
            if(r-i>MX){
                MX = r-i;
                L = i+1;
                R = r;

            }
        }
        if(MX ==0)cout<<-1<<endl;
        else cout<<L<<" "<<R<<endl;

    }
    return 0;
}