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
    int T = 1,n;
    cin>>T;
    while(T--){
        cin>>n;
        vector<int> a(n);
        for(auto &c:a)cin>>c;
        vector<int> b(n);
        for(auto &c:b)cin>>c;
        a.push_back(0);
        b.push_back(0);
        vector<int> suf1(n);
        vector<int> suf2(n);
        suf1[n-1] = a[n-1]+1;
        suf2[n-1] = b[n-1]+1;
        int last = n-1;
        for(int i= n-2;i>=0;i--){
            if(a[i]+1+(last-i)>a[last]){
                suf1[i] = a[i]+(n-i);
                last = i;
            }
            else suf1[i] = suf1[last];

            if(b[i]+1+(last-i)>b[last]){
                suf1[i] = a[i]+(n-i);
                last = i;
            }
            else suf1[i] = suf1[last];
        }

        int x = 0;
        int ans = 1e18;
        for(int i = 0;i<n;i++){
            if(i&1){
                x = max(x,b[i]);
                x = max(x+1,a[i]);
                int mx1 = st1.query(i+1,n);
                int y = max(x,mx1);
                int mx2 = st2.query(i+1,n);
                y = max(y,mx2);
                ans = min(ans,y);
                cout<<y<<endl;
            }
            else{
                x = max(x,a[i]);
                x = max(x+1,b[i]);
                int mx1 = st2.query(i+1,n);
                int y = max(x,mx1);
                int mx2 = st1.query(i+1,n);
                y = max(y,mx2);
                ans = min(ans,y);
                cout<<y<<endl;
            }
            x++;
        }
        cout<<ans<<endl;
    }
    return 0;
}