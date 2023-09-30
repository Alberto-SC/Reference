#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'


const int inf = 1e9;
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
        if(r<l)return inf;
		for (l += n, r += n; l <= r; l = (l + 1) / 2, r = (r - 1) / 2) {
			if (l & 1) ans = min(ans, st[l]);
			if (~r & 1) ans = min(ans, st[r]);
		}
		return ans;
	}
};

signed main(){__
  int T,n;
  cin>>T;
  while(T--){
    cin>>n;
    vector<int> nums(n);
    for(auto &c:nums)cin>>c;
    STmin st(n);
    set<int> S;
    vector<int> idx[n+1];
    for(int i = 0;i<n;i++){
      st.update(i,nums[i]);
      S.insert(nums[i]);
      idx[nums[i]].push_back(i);
    }
    vector<int> toCheck;
    for(auto d:S){
      toCheck.push_back(d);
    }
    int ans = 0;
    reverse(toCheck.begin(),toCheck.end());
    for(auto d:toCheck){
      int l = idx[d][0];
      //cout<<d<<" "<<l<<" "<<st.query(l+1,n-1)<<endl;
      if(st.query(l+1,n-1)<d){
        ans++;
        for(auto j: idx[d]){
          st.update(j,0);
        }
      }
    }
  
    cout<<ans<<endl;  

  }
  return 0;
}
