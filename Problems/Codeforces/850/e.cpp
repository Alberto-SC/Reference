#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long


vector<int> st;
vector<int> lazy;
void propagate(int v,int l ,int r){
    if(!lazy[v])return ;
	// For asigments replace += to = 
    st[v] = ((r-l)+1)*lazy[v];
    if(l!= r){
        lazy[v<<1] += lazy[v];
        lazy[v<<1|1]+= lazy[v];
    }
    lazy[v] = 0;
}
int n; /*+ n is global for use default values and send less parameters */
void update(int l,int r,int val,int v = 1,int sl = 0,int sr = n-1){
    propagate(v,sl,sr);
    if(r<sl || l>sr || sl>sr)return ;
    if(sl>= l && sr<=r){
        lazy[v] += val;
        propagate(v,sl,sr);
        return;
    }
    int m = (sl+sr)>>1;
    update(l,r,val,v<<1,sl,m);
    update(l,r,val,v<<1|1,m+1,sr);
    st[v] = st[v<<1]+st[v<<1|1];
}

int query(int l,int r,int v = 1,int sl = 0,int sr = n-1){
    propagate(v,sl,sr);
    if(r<sl || l>sr || sl>sr)return 0; 
    if(sl>= l && sr<=r)return st[v];
    int m = (sl+sr)>>1;
    return query(l,r,v<<1,sl,m)+query(l,r,v<<1|1,m+1,sr);
}



signed main(){__
    int T = 1;
    cin>>T;
    while(T--){
        cin>>n;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        vector<int> ans(n);
        ans[0] = nums[0]-1;
        st.resize(4*n);
        lazy.resize(4*n);

        for(int i = 1;i<n;i++){
             // if(st.count(nums[i])){
            //     int t  = ft2.query(st.size()+1)+1;
            //     cout<<t<<" "<<st.size()<<endl;
            //     ans[i] = ans[i-1]+max(0ll,nums[i]-t);
            //     ft2.update(nums[i],1);
            //     continue;
            // }

            int l = ft.query(nums[i]+1);
            int r = ft.query(n+1)-ft.query(nums[i]+1);
        
            ans[i] = nums[i]-(l+1);
            ans[i]+=ans[i-1];
            ans[i]-=r;
            ans[i] = max(0ll,ans[i]);

            ft.update(nums[i],1);
            st.insert(nums[i]);
        }
        for(auto c:ans)cout<<c<<" ";
        cout<<endl;
    }
    return 0;
}