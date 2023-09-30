#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

const int inf = 1e9;
struct STmax{
    int n;
    vector<int> st;
    STmax(int n):n(n){
        st.resize(2*n,-inf);
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

signed main(){__
    int T = 1,n;
    cin>>T;
    while(T--){
        cin>>n;
        vector<int> nums(n/2);
        for(auto &c:nums)cin>>c;
        STmax st(n/2);
        vector<int> ans(n);
        set<int> rest;
        for(int i = 1;i<=n;i++)rest.insert(i);
        for(int i = 0;i<n/2;i++){
            ans[(i*2)+1] = nums[i];
            st.update(i,nums[i]);
            rest.erase(nums[i]);
        }
        bool flag = true;
        vector<int> r;
        for(auto c:rest)r.push_back(c);
        reverse(r.begin(),r.end());
        for(auto c:r){
            int l = -1 ,r = n/2;
            // cout<<"C: "<<c<<endl;
            while(l+1<r){
                int m = (l+r)>>1;
                // cout<<m<<" "<<st.query(m,(n/2)-1)<<endl;
                if(st.query(m,(n/2)-1)>=c)l = m;
                else r = m;
            }
            // cout<<l<<endl;
            if(l ==-1){
                flag = false;
                break;
            }
            else ans[l*2] = c;
            st.update(l,-inf);
        }
        if(flag){
            for(auto c:ans)cout<<c<<" ";
            cout<<endl;
        }
        else cout<<-1<<endl;
    }
    return 0;
}