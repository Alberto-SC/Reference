#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
const lli mod = 998244353;
vector<lli> st;
int n;
void update(int idx,lli val,int v = 1,int l = 0,int r = n-1){
    if(l==r)
        (st[v]+= val)%=mod;
    else{
        int m = (l+r)>>1;
        if(idx<=m)
            update(idx,val,v<<1,l,m);
        else    
            update(idx,val,v<<1|1,m+1,r);
        st[v] = (st[v<<1]+st[v<<1|1])%mod;
    }
}

lli query(int l,int r,int v = 1,int sl = 0,int sr = n-1){
    if(sl>r || sl >sr ||sr<l)return 0;
    if(sl>=l && sr<=r){
        return st[v];
    }
    int m = (sl+sr)>>1;
    return (query(l,r,v<<1,sl,m)+query(l,r,v<<1|1,m+1,sr))%mod;
}

int main(){
    int k,l,r;
    cin>>n>>k;
    vector<pair<int,int>> segments(k);
    for(int i = 0;i<k;i++){
        cin>>l>>r;
        segments[i] ={l,r};
    }
    st.resize(4*n);
    update(0,1);
    for(int i = 1;i<n;i++){
        for(int j = 0;j<k;j++){
            l = segments[j].first;
            r = segments[j].second;
            l = i-l;
            r = i-r;
            if(l<0)continue;
            if(r<0)r = 0;
            update(i,query(r,l));
        }
    }
    cout<<endl;
    cout<<query(n-1,n-1)<<endl;
    return 0;
}
