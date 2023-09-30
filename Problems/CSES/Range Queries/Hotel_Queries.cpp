#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
vector<int> st;
int n;
void update(int idx,int x,int v = 1,int l = 0,int r = n-1){
    if(l == r)st[v] += x;
    else {
        int m = (l+r)>>1;
        if(idx<=m)
            update(idx,x,v<<1,l,m);
        else 
            update(idx,x,v<<1|1,m+1,r);
        st[v] = max(st[v<<1],st[v<<1|1]);
    }
}

int query(int x,int v = 1,int l = 0,int r = n-1){
    if(st[v]<x)return 0;
    if(l == r)return l+1;
    int m = (l+r)>>1;
    if(st[v<<1]>=x)
        return query(x,v<<1,l,m);
    else 
        return query(x,v<<1|1,m+1,r);
}
signed main(){
    int m,x;
    cin>>n>>m;
    st.resize(4*n);
    vector<int> nums(n);
    for(auto &c:nums)cin>>c;
    for(int i = 0;i<n;i++)update(i,nums[i]);
    for(int i = 0;i<m;i++){
        cin>>x;
        int idx = query(x);
        cout<<idx<<" ";
        if(idx)update(idx-1,-x);
    }
    cout<<endl;
    return 0;
}