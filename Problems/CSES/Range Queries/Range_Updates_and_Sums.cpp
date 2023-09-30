#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
vector<lli> st;
vector<pair<lli,lli>> lazy;
lli n;
 

void update(lli l,lli r,lli x ,lli op,lli v = 1,lli sl =0 ,lli sr = n-1){
    propagate(v,sl,sr);
    if(sl>r || sr<l || sl>sr)return ;
    if(sl>=l && sr<=r){
        lazy[v] = {x,op};
        propagate(v,sl,sr);
        return ;
    }
    lli m = (sl+sr)>>1;
    update(l,r,x,op,v<<1,sl,m);
    update(l,r,x,op,v<<1|1,m+1,sr);
    st[v] = st[v<<1]+st[v<<1|1];
}

lli query(lli l,lli r,lli v = 1,lli sl = 0,lli sr = n-1){
    propagate(v,sl,sr);
    if(sl>r || sr<l || sl>sr)return 0;
    if(sl>=l && sr<=r)return st[v];
    lli m = (sl+sr)>>1;
    return query(l,r,v<<1,sl,m)+query(l,r,v<<1|1,m+1,sr);
}


int main(){
    lli q,l,r,x,t;
    cin>>n>>q;
    lazy.resize(4*n);
    st.resize(4*n);
    vector<lli> nums(n);
    for(auto &c:nums)cin>>c;
    for(lli i = 0;i<n;i++)update(i,i,nums[i],1);
    for(lli i = 0;i<n;i++){
        cin>>t;
        cin>>l>>r;
        l--,r--;
        if(t == 1)
            cin>>x,update(l,r,x,1);
        else if(t==2)
            cin>>x,update(l,r,x,2);
        else
            cout<<query(l,r)<<endl;
    }
    return 0;
}