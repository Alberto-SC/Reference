#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
const int inf = 1e9;
struct ST{
    int n;
    vector<int> st;
    ST(int n):n(n){
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

int main(){
	int t= 1,n;
    cin>>t;
    while(t--){
        cin>>n;
        ST segT(n);
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        for(int i = 0;i<n;i++)
            segT.update(i,nums[i]);
        string ans(n,'1');
        for(int i = 1;i<=n;i++){
            vector<int> nw;
            for(int j = 0;j<=n-i;j++){
                nw.push_back(segT.query(j,(j+i)-1));
            }
            sort(nw.begin(),nw.end());
            for(int z =1;z<nw.size();z++)
                if(nw[z] != nw[z-1]+1)ans[i-1] = '0';
            if(nw[0]!= 1)ans[i-1]= '0';
        }
        cout<<ans<<endl;
    }
    return 0;
}  

