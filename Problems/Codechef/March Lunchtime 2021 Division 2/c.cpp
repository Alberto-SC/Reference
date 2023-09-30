#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

const int inf = 1e15;
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
 


signed main(){__
	int t= 1,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        vector<int> copy = nums;
        vector<int> u;
        sort(copy.begin(),copy.end());
        int last = copy[0];
        u.push_back(last);
        for(int i = 0;i<n;i++){
            if(copy[i]!= last){
                last = copy[i];
                u.push_back(last);
            }
        }
        for(int i = 0;i<n;i++)
            nums[i]= lower_bound(u.begin(),u.end(),nums[i])-u.begin();
        ST st(n);
        vector<int> pos[u.size()];
        for(int i =0 ;i<n;i++){
            pos[nums[i]].push_back(i);
            st.update(i,nums[i]);
        }
        vector<int> ans(n);
        for(int i = 0;i<n;i++){
            if(pos[nums[i]].size()<=1){
                ans[i] = 0;
                continue;
            }
            int idx = lower_bound(pos[nums[i]].begin(),pos[nums[i]].end(),i)-pos[nums[i]].begin();
            int l = idx,r = pos[nums[i]].size();
            while(l+1<r){
                int m = (l+r)>>1;
                if(st.query(pos[nums[i]][idx],pos[nums[i]][m])>nums[i])
                    r = m;
                else 
                    l = m;
            }
            ans[i]+=l-idx;
            r = idx,l = -1;
            while(l+1<r){
                int m = (l+r)>>1;
                if(st.query(pos[nums[i]][m],pos[nums[i]][idx])>nums[i])
                    l = m;
                else 
                    r = m;
            }
            ans[i]+=idx-r;
        }
        for(auto c:ans)cout<<c<<" ";
        cout<<endl;
    }
    return 0;
}  
