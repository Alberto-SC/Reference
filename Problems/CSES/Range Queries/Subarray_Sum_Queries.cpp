#include <bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
typedef long long int lli;
lli n;


struct node{
    lli mx,suf,pref,sum;
};
vector<node> st;

node merge(node l,node r){
    node res;
    res.mx = max({l.mx,r.mx,l.suf+r.pref});
    res.suf = max({r.suf,r.sum+l.suf});
    res.pref = max({l.pref,l.sum+r.pref});
    res.sum = l.sum+r.sum;
    return res;
}
void update(lli idx,lli x ,lli v = 1,lli sl = 0,lli sr = n-1){
    if(sl == sr)
        st[v] = {x,x,x,x};
    else{
        lli m = (sl+sr)>>1;
        if(idx<=m)
            update(idx,x,v<<1,sl,m);
        else    
            update(idx,x,v<<1|1,m+1,sr);
        st[v] = merge(st[v<<1],st[v<<1|1]);
    }
}

int main(){__
    lli m,idx,x;
    cin>>n>>m;
    st.resize(4*n);
    vector<lli> nums(n);
    for(auto &c:nums)cin>>c;
    for(lli i = 0;i<n;i++)
        update(i,nums[i]);

    for(lli i = 0;i<m;i++){
        cin>>idx>>x;
        idx--;
        update(idx,x);
        cout<<max(st[1].mx,0ll)<<endl;
    }
    return 0;

}