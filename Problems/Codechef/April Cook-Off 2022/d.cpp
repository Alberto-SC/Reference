#include <bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define int long long 
#define endl '\n'

struct Interval{
    bool disjoint;
    int pref,suff,L,R; 
};

vector<Interval> st;
Interval nll = {false,-1,-1,-1,-1};
int n;

Interval merge(Interval a,Interval b){
    Interval nw;
    if(a.pref ==-1)return b;
    if(b.pref ==-1)return a;
    nw.disjoint  =a.disjoint |b.disjoint; 
    nw.pref = a.pref;
    nw.suff = b.suff;
    nw.L = max(a.L,b.L);
    nw.R = min(a.R,b.R);
    int l,r;
    if(a.suff<b.pref)
        l = 0,r = (a.suff+b.pref)/2;
    else if(a.suff>b.pref)
        l = ((a.suff+b.pref)+1)/2,r = 1e12;
    else l = 0, r = 1e12;
    nw.L = max(nw.L ,l);
    nw.R = min(nw.R ,r);
    if(nw.R<nw.L)nw.disjoint = true;
    return nw;
}

void update(int idx,int val ,int v = 1,int sl =0,int sr = n-1){
    if(sl== sr){
        st[v]  ={false,val,val,0ll,1000000000000};
        return ;
    }
    int m = (sl+sr)>>1;
    if(idx<=m)update(idx,val,v<<1,sl,m);
    else update(idx,val,v<<1|1,m+1,sr);
    st[v] = merge(st[v<<1],st[v<<1|1]);
}

Interval query(int l,int r,int v = 1,int sl = 0,int sr = n-1){
    if(sl>r || sr<l || sl>sr)return nll;
    if(sl>=l  && sr<=r )return st[v];
    int m = (sl+sr)>>1;
    return merge(query(l,r,v<<1,sl,m),query(l,r,v<<1|1,m+1,sr));

}
 
signed main(){
    int t,q,l,r;
    cin>>n>>q;
    st.resize(4*n);
    vector<int> nums(n);
    for(auto &c:nums)cin>>c;
    for(int i = 0;i<n;i++)
        update(i,nums[i]);


    for(int i = 0;i<q;i++){
        cin>>t>>l>>r;
        if(t == 1){
            l--;
            update(l,r);
        }
        else{
            l--,r--;
            Interval x = query(l,r);
            // cout<<x.disjoint<<" "<<x.pref<<" "<<x.suff<<" "<<x.L<<" "<<x.R<<endl;
            if(x.disjoint)cout<<-1<<endl;
            else cout<<x.L<<endl;
        }
    }

    return 0;
}
