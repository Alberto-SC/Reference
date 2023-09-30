#include <bits/stdc++.h>
using namespace std;
vector<int> st;
#define print(A)for(auto c:st)cout<<c<<" ";cout<<endl;
void build(vector<int> &A,int v,int l ,int r,int level){
    if(l == r)st[v] = A[l];
    else{
        int m = (l+r)/2;
        build(A,v*2,l,m,level+1);
        build(A,v*2+1,m+1,r,level+1);
        if(level&1)st[v] = st[v*2] | st[v*2+1];
        else st[v] = st[v*2] ^ st[v*2+1];
    }
}
void update(int v,int sl ,int sr,int pos,int val,int level){
    if(sl == sr)st[v] = val;
    else{
        int m = (sl+sr)/2;
        if(pos<=m)update(v*2,sl,m,pos,val,level+1);
        else update(v*2+1,m+1,sr,pos,val,level+1);
        if(level&1)st[v] = st[v*2] | st[v*2+1];
        else st[v] =  st[v*2] ^ st[v*2+1];
    }
}
int main(){
    int p,m,x,pos,val;
    cin>>p>>m;
    int n = 1<<p;
    vector<int> nums(n);
    st.resize(4*n);
    for(auto &c:nums)cin>>c;
    int level;
    p&1? level= 1:level = 0;
    build(nums,1,0,n-1,level);
    for(int i = 0;i<m;i++){
        cin>>pos>>val;
        update(1,0,n-1,pos-1,val,level);
        cout<<st[1]<<endl;
    }
    return 0;
}