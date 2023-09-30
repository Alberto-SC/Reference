#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

vector<int> st;

int n;
void update(int idx,int x ,int v = 1,int sl = 0,int sr = n-1){
    if(sl == sr)st[v] = x;
    else{
        int m = (sl+sr)>>1;
        if(idx<=m)
            update(idx,x,v<<1,sl,m);
        else    
            update(idx,x,v<<1|1,m+1,sr);
        st[v] = st[v<<1]+st[v<<1|1];
    }
}

int query(int l,int r,int v = 1,int sl = 0,int sr = n-1){
    if(sl>r || sr<l || sl>sr)return 0;
    if(sl>=l && sr<=r)return st[v];
    int m = (sl+sr)>>1;
    return query(l,r,v<<1,sl,m)+query(l,r,v<<1|1,m+1,sr);
}
signed main(){__
	int t= 1,l,r,q;
    cin>>n>>q;
    st.resize(4*n);
    vector<int> nums(n);
    for(auto &c:nums)cin>>c;
    for(int i = 0;i<n;i++)
        update(i,nums[i]);
    
    for(int i = 0;i<q;i++){
        cin>>t>>l>>r;
        if(t == 1)
            update(l,r);
        else
            cout<<query(l,r-1)<<endl;
    }
    return 0;
}  
