#include <bits/stdc++.h>
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

using namespace std;

vector<int> st;
vector<int> lazy;
void propagate(int v,int l ,int r){
    if(!lazy[v])return ;
    st[v] += ((r-l)+1)*lazy[v];
    if(l!= r){
        lazy[v<<1] += lazy[v];
        lazy[v<<1|1]+= lazy[v];
    }
    lazy[v] = 0;
}
int n;
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
    int k;
    cin>>n;
    lazy.resize(4*n);
    st.resize(4*n);
    vector<int> nums(n);
    for(auto &c:nums)cin>>c;
    for(int i = 0;i<n;i++)update(i,i,nums[i]);
    int q;
    cin>>q;
    while(q--){
        int t,i,x,s;
        cin>>t;
        if(t ==1){
            cin>>i>>x>>s;
            if(i)
                update(0,i-1,-s);
            if(i !=n-1)
                update(i+1,n-1,-s);
            update(i,i,x);
        }
        else{
            cin>>i;
            cout<<query(i,i)<<endl;
        }
    }
    return 0;
}

