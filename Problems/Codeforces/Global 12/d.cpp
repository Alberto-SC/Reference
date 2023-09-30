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

vector<lli> st;
vector<lli> lazy;
void propagate(int v,int l ,int r){
    if(lazy[v]== -1)return ;
    st[v] = lazy[v];
    if(l!= r){
        lazy[v<<1] = lazy[v];
        lazy[v<<1|1]= lazy[v];
    }
    lazy[v] = -1;
}

int n;
void update(int l,int r,lli val,int v = 1,int sl = 0,int sr = n-1){
    propagate(v,sl,sr);
    if(r<sl || l>sr || sl>sr)return ;
    if(sl>= l && sr<=r){
        lazy[v] = val;
        propagate(v,sl,sr);
        return;
    }
    int m = (sl+sr)>>1;
    update(l,r,val,v<<1,sl,m);
    update(l,r,val,v<<1|1,m+1,sr);
    st[v] = st[v<<1]+st[v<<1|1];
}

lli query(int l,int r,int v = 1,int sl = 0,int sr = n-1){
    propagate(v,sl,sr);
    if(r<sl || l>sr || sl>sr)return 0;
    if(sl>= l && sr<=r)return st[v];
    int m = (sl+sr)>>1;
    return query(l,r,v<<1,sl,m)+query(l,r,v<<1|1,m+1,sr);
}
int main(){__
	int t= 1;
    cin>>t;
    while(t--){
        cin>>n;
        ST segT(n);
        st.resize(4*n,1);
        lazy.resize(4*n,-1);
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        for(int i = 0;i<n;i++)
            segT.update(i,nums[i]);
        vector<pair<int,int>> P(n);
        for(int i = 0;i<n;i++){
            int l = -1,r = i;
            while(l+1<r){
                int m = (l+r)>>1;
                if(segT.query(m,i)== nums[i])
                    r = m;
                else 
                    l = m;
            }
            P[i].first = (i-r)+1;
            l = i,r = n;
            while(l+1<r){
                int m = (l+r)>>1;
                if(segT.query(i,m)== nums[i])
                    l = m;
                else 
                    r = m;
            }
            P[i].second = (l-i)+1;
        }
        int idx = 0;
        for(int i= 0;i<n;i++)
            update(i,i,1);
        // for(int i = 0;i<n;i++)
            // cout<<query(i,i);
        // cout<<endl;
        vector<pair<int,int>> last(n+1,{-1,-1});
        for(auto c:P){
            int goodl = 1,goodr = (c.first+c.second)-1;
            goodl--,goodr--;
            // cout<<c.first<<" "<<c.second<<" "<<goodl<<" "<<goodr<<" "<<last[nums[idx]].second<<endl;
            if(c.first>1 && c.second>1)update(goodl+1,goodr-1,0);
            if(c.first>0 &&  last[nums[idx]].second>0)update(0,min(c.first,last[nums[idx]].second)-2,0);
            int mx = n-nums[idx];
            update(mx+1,goodr,0);
            last[nums[idx]] = {idx,c.second};
            idx++;
        }
        sort(nums.begin(),nums.end());
        // for(auto c:nums)cout<<c<<" ";
        // cout<<endl;
        for(int i = 1;i<n;i++)
            if(nums[i]!= nums[i-1]+1)update(0,0,0);
        if(nums[0]!= 1)update(0,0,0);
        for(int i=0;i<n;i++)
            cout<<query(i,i);
        cout<<endl;
    }
    return 0;
}  

