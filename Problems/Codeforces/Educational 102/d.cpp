#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
const int inf = 1e9+7;
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
		int ans = -inf;
        if(r<l)return 0;
		for (l += n, r += n; l <= r; l = (l + 1) / 2, r = (r - 1) / 2) {
			if (l & 1) ans = max(ans, st[l]);
			if (~r & 1) ans = max(ans, st[r]);
		}
		return ans;
	}
};

int main(){__
	int t= 1,n,l,r,q;
    cin>>t;
    while(t--){
        cin>>n>>q;
        string s;
        cin>>s;
        STmin segmin(n+1);
        STmax segmax(n+1);
        int sum = 0;
        vector<int> ac(n);
        for(int i = 0;i<n;i++){
            if(s[i] == '-')sum--;
            else sum++;
            segmin.update(i,sum);
            segmax.update(i,sum);
            ac[i] = sum;
        }
        segmax.update(n,sum);
        segmin.update(n,sum);
        for(int i = 0;i<q;i++){
            cin>>l>>r;
            l--,r--;
            int mnl = segmin.query(0,l-1);
            int mxl = segmax.query(0,l-1);
            int mnr = segmin.query(r+1,n);
            int mxr = segmax.query(r+1,n);  
            mnr-=ac[r];
            mxr-=ac[r];
            int mnt = min(mnl,(l-1>=0?ac[l-1]:0)+mnr);
            int mxt = max(mxl,(l-1>=0?ac[l-1]:0)+mxr);
            if(mxt<0)mxt = 0;
            if(mnt>0)mnt = 0;
            // cout<<mxl<<" "<<mxr<<endl;
            // cout<<mnt<<" "<<mxt<<endl;
            cout<<mxt+abs(mnt)+1<<endl;
        }
    }
    return 0;
}  

