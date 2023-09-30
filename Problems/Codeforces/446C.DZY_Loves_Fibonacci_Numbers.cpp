#include <bits/stdc++.h>
using namespace std;
typedef long long int lli ;
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
vector<lli> st;
vector<pair<int,int>> lazy;

const lli mod = 1e9+7;
lli n;

vector<lli> pre;
void propagate(lli v,lli l,lli r){
    pair<lli,lli> op = lazy[v].front();
    st[v]+= (pre[op.second]-pre[op.first-1])%mod;
    st[v]%=mod;
    if(l!= r){
        lazy[v<<1].push({op.first,op.first+(((l+r)>>1)-l)});
        lazy[v<<1|1].push({op.first+(((l+r)>>1)-l)+1,op.second});
    }
    lazy[v].pop();
}
void update(lli l,lli r,lli x = 0,lli v = 1,lli sl = 0,lli sr = n-1){
    propagate(v,sl,sr);
    if(sl>r || sr<l || sl>sr)return ;
    if(sl>=l && sr<=r){
        if(x)
            st[v] = x;
        
        else{
            lazy[v].first+=(sl-l)+1;
            lazy[v].second+=(sr-l)+1;
            propagate(v,sl,sr);
        }
        return ;
    }
    lli m = (sl+sr)>>1;
    update(l,r,x,v<<1,sl,m);
    update(l,r,x,   v<<1|1,m+1,sr);
    st[v] = (st[v<<1]+st[v<<1|1])%mod;
}

lli query(lli l,lli r,lli v = 1,lli sl = 0,lli sr = n-1){
    propagate(v,sl,sr);
    if(sl>r || sr<l || sl>sr)return 0;
    if(sl>=l && sr<=r)return st[v];
    lli m = (sl+sr)>>1;
    return (query(l,r,v<<1,sl,m)+query(l,r,v<<1|1,m+1,sr))%mod;
}

int main(){__
    lli q,l,r;
    cin>>n>>q;
    pre.push_back(0);
    pre.push_back(1);
    for(lli i = 2;i<=n;i++)
        pre.push_back((pre[i-1]+pre[i-2])%mod);
    for(lli i = 2;i<=n;i++)
        pre[i] = (pre[i]+pre[i-1])%mod;

    st.resize(4*n);
    lazy.resize(4*n);
    vector<lli> nums(n);
    for(auto &c:nums)cin>>c;
    for(lli i = 0;i<n;i++)
        update(i,i,nums[i]);
    
    for(lli i = 0;i<q;i++){
        lli t;
        cin>>t;
        cin>>l>>r;
        l--,r--;
        if(t ==1)
            update(l,r);
        else
            cout<<query(l,r)<<endl;
    }
    return 0;
}