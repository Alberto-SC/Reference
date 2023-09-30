#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

vector<pair<int,int>> st;

int n;
void update(int idx,int x ,int v = 1,int sl = 0,int sr = n-1){
    if(sl == sr)st[v] = {x,1};
    else{
        int m = (sl+sr)>>1;
        if(idx<=m)
            update(idx,x,v<<1,sl,m);
        else    
            update(idx,x,v<<1|1,m+1,sr);
        if(st[v<<1].first==st[v<<1|1].first){
            st[v].first = st[v<<1].first;
            st[v].second = st[v<<1].second+st[v<<1|1].second;
        }
        else
            st[v] = min(st[v<<1],st[v<<1|1]);
    }
}

pair<int,int> query(int l,int r,int v = 1,int sl = 0,int sr = n-1){
    if(sl>r || sr<l || sl>sr)return {1e9+7,1}; 
    if(sl>=l && sr<=r)return st[v];
    int m = (sl+sr)>>1;
    pair<int,int> L ,R;
    L = query(l,r,v<<1,sl,m);
    R = query(l,r,v<<1|1,m+1,sr);
    if(L.first==R.first){
        return {L.first,L.second+R.second};
    }
    else
        return min(L,R);
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
            cout<<query(l,r-1).first<<" "<<query(l,r-1).second<<endl;
    }
    return 0;
}  
