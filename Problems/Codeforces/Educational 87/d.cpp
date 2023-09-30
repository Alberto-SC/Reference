#include <bits/stdc++.h>
using namespace std;

vector<int> st;

void update(int v,int l,int r,int pos,int val){
    if(l== r)st[v]+=val;
    else {
        int mid = (l+r)>>1;
        if(pos<=mid)
            update(v<<1,l,mid,pos,val);
        else 
            update(v<<1|1,mid+1,r,pos,val);
        st[v] = st[v<<1]+st[v<<1|1];
    }
}

int find(int v,int l,int r,int sum){
    if(l == r)return l;
    int mid = (l+r)>>1;
    if(sum<=st[v<<1])
        find(v<<1,l,mid,sum);
    else 
        find(v<<1|1,mid+1,r,sum-st[v<<1]);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,q,x;
    cin>>n>>q;
    st.resize(4*(n+1));
    for(int i=0;i<n;i++){
        int c;cin>>c;
        update(1,0,n,c,1);

    }
    for(int i = 0;i<q;i++){
        cin>>x;
        if(x<0){
            int z = find(1,0,n,abs(x));
            update(1,0,n,z,-1);
        }
        else update(1,0,n,x,1);
    }
    if(st[1]==0)return cout<<0<<endl,0;
    cout<<find(1,0,n,1)<<endl;
    return 0;
}