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
    int T = 1,n,m;
    cin>>T;
    while(T--){
        cin>>n;
        map<int,int> mp;
        vector<int> a(n);
        vector<int> b(n);
        for(auto &c:a)cin>>c;
        for(auto &c:b)cin>>c;
        cin>>m;
        for(int i = 0;i<m;i++){
            int x;
            cin>>x;
            mp[x]++;
        }
        STmax st(n);
        bool flag = true;
        for(int i = 0;i<n;i++){
            st.update(i,b[i]);
            if(a[i]<b[i])flag = false;
        }

        map<int,vector<int>> pos;
        for(int i = 0;i<n;i++){
            pos[b[i]].push_back(i);
        }

        for(auto c:pos){
            bool _all = true;
            int last = 0;
            // cout<<"X: "<<c.first<<endl;
            if(a[c.second[0]]!=b[c.second[0]])_all = false;
            // cout<<_all<<endl;
            for(int i = 1;i<c.second.size();i++){
                if(st.query(c.second[last],c.second[i]) != c.first){
                    if(!_all)
                        mp[c.first]--;
                    
                    _all = true;
            
                    last = i;
                }
                if(a[c.second[i]]!=b[c.second[i]])_all = false;
            }
            if(!_all)mp[c.first]--;

        }

        for(auto c:mp){
            if(c.second<0)flag = false;
        }
        if(flag)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
// 0 1 2 3 4 5 6 7 8 9  10 11 12 
// 7 9 4 5 3 3 3 6 8 10 3  2  5
// 5 3 1 5 3 2 2 5 8 5  1  1  5