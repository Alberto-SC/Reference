#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define x first
#define y second

vector<int> st;
vector<int> lazy;

int n;
void propagate(int l,int r,int v){
    st[v] += lazy[v];
    if(l!= r){
        lazy[v<<1] += lazy[v];
        lazy[v<<1|1]+=lazy[v];
    }
    lazy[v] = 0;
}

void update(int l,int r,int x,int v = 1,int sl = 0,int sr = n-1){
    propagate(sl,sr,v);
    if(sl>r || sr<l || sl>sr)return ;
    if(sl>=l && sr<=r){
        lazy[v] +=x;
        propagate(sl,sr,v);
        return ;
    }
    int m = (sl+sr)>>1;
    update(l,r,x,v<<1,sl,m);
    update(l,r,x,v<<1|1,m+1,sr);
    st[v] = min(st[v<<1],st[v<<1|1]);
}

const int inf = 1e17;
int query(int l,int r,int v = 1,int sl= 0,int sr = n-1){
    propagate(sl,sr,v);
    if(sl>r || sr<l ||sl>sr)return inf;
    if(sl>=l && sr<=r)return st[v];
    int m = (sl+sr)>>1;
    return min(query(l,r,v<<1,sl,m),query(l,r,v<<1|1,m+1,sr));

}
void print(){
    for(int i = 0;i<n;i++)
        cout<<query(i,i)<<" ";
    cout<<endl;

}


signed main(){__
    cin>>n;
    st.resize(4*n);
    lazy.resize(4*n);
    vector<int> nums(n);
    for(auto &c:nums)cin>>c;
    vector<pair<int,int>> _all;
    int ans = 0;
    for(int i = 0;i<n;i++)
        _all.push_back({nums[i],i});
    
    sort(_all.rbegin(),_all.rend());
    for(int i = 0;i<n;i++){ 
        int mn = query(_all[i].y,n-1);
        if(_all[i].x+mn>=0){
            ans++;
            update(_all[i].y,n-1,_all[i].x);
        }
    }
    cout<<ans<<endl;
    return 0;
}  
