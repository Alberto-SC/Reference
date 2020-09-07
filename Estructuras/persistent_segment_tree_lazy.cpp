#include <bits/stdc++.h>
using namespace std;
const int maxn = 800007;
int L[maxn],R[maxn],st[maxn],lazy[maxn],N;
int n;

int newLeaf(int val){
    int p = ++N;
    L[p] = R[p] = 0;
    st[p] = val;
    return p;
}

int newParent(int l,int r){
    int p = ++N;
    L[p] = l;
    R[p] = r;
    st[p] = st[l]+st[r];
    return p;
}

int newLazy(int v,int val,int l,int r){
    int p = ++N;
    L[p] = L[v];
    R[p] = R[v];
    lazy[p] += val;
    st[p] = st[v]+((r-l)+1)*val;
    return p;
}

int build(vector<int> &A,int l = 0,int r = n-1){
    if(l== r)return newLeaf(A[l]);
    int mid = (l+r)>>1;
    return newParent(build(A,l,mid),build(A,mid+1,r));
}

void propagate(int p,int l,int r){
    if(lazy[p]==0)return;
    if(l!= r){
        int mid = (l+r)>>1;
        L[p] = newLazy(L[p],lazy[p],l,mid);
        R[p] = newLazy(R[p],lazy[p],mid+1,r);
    }
    lazy[p] = 0;
}

int update(int l,int r,int val,int p,int sl = 0 ,int sr = n-1){
    if(sr<l || sl>r)return p;
    if(sl>=l && sr<=r)return newLazy(p,val,sl,sr);
    propagate(p,sl,sr);
    int mid = (sl+sr)>>1;
    return newParent(update(l,r,val,L[p],sl,mid),update(l,r,val,R[p],mid+1,sr));
}

int query(int l,int r,int p,int sl = 0,int sr = n-1){
    if(sr<l || sl> r)return 0;
    if(sl>=l && sr<=r)return st[p];
    int mid = (sl+sr)>>1;
    propagate(p,sl,sr);
    return query(l,r,L[p],sl,mid)+query(l,r,R[p],mid+1,r);
}

int main(){
    int l,r,val,t,type,q;
    cin>>n;
    vector<int> nums(n);
    for(auto &c:nums)cin>>c;
    cin>>q;
    vector<int> versions;
    versions.push_back(build(nums));
    for(int i = 0;i<q;i++){
        cin>>type;
        if(type == 1){
            cin>>l>>r>>val;
            l--,r--;
            versions.push_back(update(l,r,val,versions.back()));
        }
        else{
            cin>>l>>r>>t;
            l--,r--,t--;
            cout<<query(l,r,versions[t])<<endl;
        }
    }
    return 0;
}