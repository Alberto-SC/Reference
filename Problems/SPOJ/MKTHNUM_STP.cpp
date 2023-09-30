#include <bits/stdc++.h>
using namespace std;
const int maxn = 2000000;
int L[maxn],R[maxn],st[maxn],N;

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
int n;

int build(vector<int> &A,int l = 0,int r = n-1){
    if(l == r)return newLeaf(A[l]);
    int mid = (l+r)>>1;
    return newParent(build(A,l,mid),build(A,mid+1,r));
}

int update(int pos ,int val ,int p,int l = 0,int r = n-1){
    if(l == r)return newLeaf(st[p]+val);
    int mid = (l+r)>>1;
    if(pos<=mid)
        return newParent(update(pos,val,L[p],l,mid),R[p]);
    else 
        return newParent(L[p],update(pos,val,R[p],mid+1,r));
}

int query(int p1,int p2,int k,int l = 0,int r =n-1){
    if(l == r)return l;
    int cont = st[L[p1]]-st[L[p2]];
    int mid = (l+r)>>1;
    if(cont>=k)
        return query(L[p1],L[p2],k,l,mid);
    else    
        return query(R[p1],R[p2],k-cont,mid+1,r);
}

int main(){
    int q,l,r,k;
    cin>>n>>q;
    vector<int> nums(n);
    vector<int> copy(n);
    for(int i = 0;i<n;i++){
        cin>>nums[i];
        copy[i] =nums[i];
    }
    vector<int> uniques;
    sort(copy.begin(),copy.end());
    int last = copy[0];
    uniques.push_back(last);
    for(int i = 1;i<n;i++){
        if(copy[i]!= last){
            last = copy[i];
            uniques.push_back(last);
        }
    }
    for(int i = 0;i<n;i++)
        nums[i] = lower_bound(uniques.begin(),uniques.end(),nums[i])-uniques.begin();
    
    vector<int> prefixes;
    vector<int> A(n,0);
    int root = build(A);
    prefixes.push_back(root);
    for(int i = 0;i<n;i++)
        prefixes.push_back(update(nums[i],1,prefixes.back()));
    
    for(int i = 0;i<q;i++){
        cin>>l>>r>>k;
        cout<<uniques[query(prefixes[r],prefixes[l-1],k)]<<endl;
    }

    return 0;
}