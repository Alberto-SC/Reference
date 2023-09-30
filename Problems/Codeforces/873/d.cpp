#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

int inf = 1e9+7;

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


int n;
#define print(A)for(auto c:A)cout<<c<<" ";cout<<endl;
#define printM(A)for(auto c:A){print(c);}
vector<int> bit;
int sum(int idx) {
    int ret = 0;
    for (++idx; idx > 0; idx -= idx & -idx)ret += bit[idx];
    return ret;
}

int sum(int l, int r) {
    return sum(r) - sum(l - 1);
}

void add(int idx, int delta) {
    for (++idx; idx < n; idx += idx & -idx) bit[idx] += delta;
}


signed main(){__
    int T = 1;
    cin>>T;
    while(T--){
        cin>>n;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;

        vector<int> s = nums;
        sort(s.begin(),s.end());

        for(int i = 0;i<n;i++)
            nums[i] = lower_bound(s.begin(),s.end(),nums[i])-s.begin();
        

        long long ans = 0;

        STmin st(n);
        bit.assign(n+1,0);

        for(int i = 0;i<n;i++){
            for(int j = 0;j<n-i;j++)
                st.update(j,inf);

            vector<int> dp(n-i,0);
            vector<int> last(n-i,-1);
            
            for(int j = i;j<n;j++){
                int pos = sum(0,nums[j]-1);
                int currentId = j-i;
                if(pos == currentId){
                    last[currentId] = currentId;
                    dp[currentId] = currentId? dp[currentId-1]:0;
                }
                else{
                    int mn = st.query(pos,currentId-1);
                    int dist = currentId-mn;
                    dp[currentId] = dist+(mn?dp[mn-1]:0);
                    last[currentId] = mn;
                }
                st.update(currentId,last[currentId]);
                add(nums[j],1);
                ans+=dp[currentId];
            }
            for(int j = i;j<n;j++){
                add(nums[j],-1);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}