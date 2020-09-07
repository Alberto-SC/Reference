#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
vector<lli> st;
vector<lli> lazy;
void propagate(int v,int l ,int r){
    if(!lazy[v])return ;
    st[v] += ((r-l)+1)*lazy[v];
    if(l!= r){
        lazy[v<<1] += lazy[v];
        lazy[v<<1|1]+= lazy[v];
    }
    lazy[v] = 0;
}

void update(int v,int sl,int sr,int l,int r,lli val){
    propagate(v,sl,sr);
    if(r<sl || l>sr || sl>sr)return ;
    if(sl>= l && sr<=r){
        lazy[v] += val;
        propagate(v,sl,sr);
        return;
    }
    int m = (sl+sr)>>1;
    update(v<<1,sl,m,l,r,val);
    update(v<<1|1,m+1,sr,l,r,val);
    st[v] = st[v<<1]+st[v<<1|1];
}

lli query(int v,int sl,int sr,int l,int r){
    propagate(v,sl,sr);
    if(r<sl || l>sr || sl>sr)return 0;
    if(sl>= l && sr<=r)return st[v];
    int m = (sl+sr)>>1;
    return query(v<<1,sl,m,l,r)+query(v<<1|1,m+1,sr,l,r);
}

int main(){
    int n,m,t,l,r,v;
    cin>>n;
    st.resize(4*n,0);
    lazy.resize(4*n,0);
    vector<int> nums(n);
    for(int i = 0;i<n;i++){
        cin>>nums[i];
        update(1,0,n-1,i,i,nums[i]);
    }
    cin>>m;
    // for(int i = 0;i<10;i++){cout<<st[i]<<" ";}
    // cout<<endl;
    // for(int i = 0;i<10;i++){cout<<lazy[i]<<" ";}
    // cout<<endl;
    for(int i = 0;i<m;i++){
        cin>>t;
        if(t == 0){
            cin>>l>>r>>v;
            update(1,0,n-1,l,r,v);
        }
        else {
            cin>>l>>r;
            cout<<query(1,0,n-1,l,r)<<endl;
        }
    }
    return 0;
}