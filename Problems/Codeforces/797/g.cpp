#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

vector<int> st;
vector<int> lazy;
int n;
void propagate(int v,int l ,int r){
    if(lazy[v]==-1)return ;
    st[v] = ((r-l)+1)*lazy[v];
    if(l!= r){
        lazy[v<<1] = lazy[v];
        lazy[v<<1|1] = lazy[v];
    }
    lazy[v] = -1;
}

void update(int l,int r,int val,int v = 1,int sl = 0,int sr = n-1){
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

int query(int l,int r,int v = 1,int sl = 0,int sr =n-1){
    propagate(v,sl,sr);
    if(r<sl || l>sr || sl>sr)return 0;
    if(sl>= l && sr<=r)return st[v];
    int m = (sl+sr)>>1;
    return query(l,r,v<<1,sl,m)+query(l,r,v<<1|1,m+1,sr);
}

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
        if(r<l)return 0;
		for (l += n, r += n; l <= r; l = (l + 1) / 2, r = (r - 1) / 2) {
			if (l & 1) ans = min(ans, st[l]);
			if (~r & 1) ans = min(ans, st[r]);
		}
		return ans;
	}
};

signed main(){__
    int t,k,q,x;
    cin>>t;
    while(t--){
        cin>>n>>q;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        st.resize(4*n,0);
        lazy.resize(4*n,-1);
        STmin STM(n);
        for(int i = 0;i<n;i++)
            STM.update(i,nums[i]),update(i,i,1);

        int idx = 0;
        while(idx<n){
            int l = idx,r = n;
            while(l+1<r){
                int m =(l+r)>>1;
                if(STM.query(idx+1,m)>=nums[idx])
                    l = m;
                else 
                    r = m;
            }
            if(idx+1<=l)
                update(idx+1,l,0);
            idx = r;
        }
        while(q--){
            cin>>idx>>x;
            idx--;
            int num = STM.query(idx,idx);
            STM.update(idx,num-x);

            int l = -1,r = idx+1;
            while(l+1<r){
                int m =(l+r)>>1;
                if(query(m,idx)>=1)
                    l = m;
                else 
                    r = m;
            }
            // cout<<l<<" "<<r<<" ";
            // cout<<STM.query(l,l)<<" "<<STM.query(idx,idx)<<endl;
            if(STM.query(l,l) >STM.query(idx,idx)&& l!=idx)
                update(idx,idx,1);
        
            l = idx,r = n;
            while(l+1<r){
                int m =(l+r)>>1;
                if(STM.query(idx+1,m)>=STM.query(idx,idx))
                    l = m;
                else 
                    r = m;
            }
            // cout<<l<<" "<<r<<endl;
            if(idx+1<=l)
                update(idx+1,l,0);
            // for(int i = 0;i<n;i++)
                // cout<<query(i,i)<<" ";
            // cout<<endl;
            cout<<query(0,n-1)<<" ";
        }
        cout<<endl;
    }
    return 0;
}
