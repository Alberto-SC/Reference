#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
const int inf = 1e15;
struct STMAX{
    int n;
    vector<int> st;
    STMAX(int n):n(n){
        st.resize(2*n,inf);
    }
	inline void update(int x, int val) {
		x += n;
		st[x] = val;
		for (; x >>=1 ; st[x] = max(st[x<<1], st[x<<1|1]));
	}
	inline int query(int l, int r) {
		int ans = -inf;
		for (l += n, r += n; l <= r; l = (l + 1) / 2, r = (r - 1) / 2) {
			if (l & 1) ans = max(ans, st[l]);
			if (~r & 1) ans = max(ans, st[r]);
		}
		return ans;
	}
};

struct STMIN{
    int n;
    vector<int> st;
    STMIN(int n):n(n){
        st.resize(2*n,inf);
    }
	inline void update(int x, int val) {
		x += n;
		st[x] = val;
		for (; x >>=1 ; st[x] = min(st[x<<1], st[x<<1|1]));
	}
	inline int query(int l, int r) {
		int ans = inf;
		for (l += n, r += n; l <= r; l = (l + 1) / 2, r = (r - 1) / 2) {
			if (l & 1) ans = min(ans, st[l]);
			if (~r & 1) ans = min(ans, st[r]);
		}
		return ans;
	}
};

signed main(){__
    int n,q,l,r,x;
    cin>>n>>q;
    vector<int> nums(n);
    for(auto &c:nums)cin>>c;
    STMIN stmn(n);
    STMAX stmx(n);
    for(int i = 0;i<n;i++){
        stmn.update(i,nums[i]);
        stmx.update(i,nums[i]);
    }
    string t;
    for(int i = 0;i<q;i++){
        cin>>t;
        if(t =="MAX"){
            cin>>l>>r;
            l--,r--;
            cout<<stmx.query(l,r)<<endl;
        }
        else if(t =="MIN"){
            cin>>l>>r;
            l--,r--;
            cout<<stmn.query(l,r)<<endl;
        }
        else{
            cin>>l>>r;
            l--;
            stmx.update(l,r);
            stmn.update(l,r);
        }
    }

}