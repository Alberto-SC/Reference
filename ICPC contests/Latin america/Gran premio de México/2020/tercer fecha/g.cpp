#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
const int maxn = 100007;
vector<int> gold(maxn);
vector<int> A(maxn);
vector<int> B(maxn);
vector<int> st;
int DP[2*maxn];
int n;
const int inf = 1e9+7;
struct ST{
    int n;
    vector<int> st;
    ST(int n):n(n){
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
int main(){__
	int t= 1,m;
    cin>>n;
    ST st(2*n);
    for(int i = n;i<=n*2;i++)st.update(i,0);
    memset(DP,-1,sizeof(DP));
    for(int i = 0;i<n;i++){
        cin>>gold[i]>>A[i]>>B[i];
    }
    for(int i = n-1;i>=0;i--){
        DP[i] = gold[i]+st.query(i+A[i],i+B[i]);
        st.update(i,DP[i]);
        // cout<<DP[i]<<" ";
    }
    // cout<<endl;
    int mx = 0;
    for(int i = 0;i<n;i++)
        mx = max(DP[i],mx);
    cout<<mx<<endl;
    return 0;  
}  

