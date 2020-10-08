#include <bits/stdc++.h>
using namespace std;
int n;
const int maxn = 800007;
int L[maxn],R[maxn],st[maxn], N;

int newLeaf(int val){
    int p = ++N;
    L[p] = R[p] = 0;
    st[p]= val;
    return p;
}

int newParent(int l,int r){
    int p = ++N;
    L[p] = l;
    R[p] = r;
    st[p] = st[l]+st[r];
    return p;
}

int build(vector<int> &A,int l = 0,int r = n-1){
    if(l == r) return newLeaf(A[l]);
    else {
        int m = (l+r)>>1;
        return newParent(build(A,l,m), build(A,m+1,r));
    }
}

int update(int pos,int val,int p ,int l = 0,int r = n-1){
    if(l == r)return newLeaf(st[p]+val);
    int mid = (l+r)>>1;
    if(pos<=mid)
        return newParent(update(pos,val,L[p],l,mid),R[p]);
    else 
        return newParent(L[p],update(pos,val,R[p],mid+1,r));
    

}

int query(int l,int r ,int p ,int sl = 0,int sr = n-1){
    if(sr<l || sl>r)return 0;
    if(sl>=l && sr<=r)return st[p];
    int mid = (sl+sr)>>1;
    return query(l,r,L[p],sl,mid)+query(l,r,R[p],mid+1,sr);
}


// QUERY for kth less number in a range
// [ TESTED IN SPOJ -MKTHNUM , COT]
// int query(int p1,int p2,int k,int l = 0,int r =n-1){
//     if(l == r)return l;
//     int cont = st[L[p1]]-st[L[p2]];
//     int mid = (l+r)>>1;
//     if(cont>=k)
//         return query(L[p1],L[p2],k,l,mid);
//     else    
//         return query(R[p1],R[p2],k-cont,mid+1,r);
// }

int main(){
    int q,idx,val,type,l,r,t;
    cin>>n;
    vector<int> nums(n);
    for(auto &c:nums)cin>>c;
    int root = build(nums);
    cin>>q;
    vector<int> versions;
    versions.push_back(root);
    for(int i = 0;i<q;i++){
        cin>>type;
        if(type == 1){
            cin>>idx>>val;
            idx--;
            versions.push_back(update(idx,val,versions.back()));
        }
        else {
            cin>>l>>r>>t;
            l--,r--;
            t--;
            cout<<query(l,r,versions[t])<<endl;
        }
        
    }

    // for kth less number in a range 
    // needs coordinades compression

    // vector<int> prefixes;
    // vector<int> A(n,0);
    // int root = build(A);
    // prefixes.push_back(root);
    // for(int i = 0;i<n;i++)
    //     prefixes.push_back(update(nums[i],1,prefixes.back()));
    
    // for(int i = 0;i<q;i++){
    //     cin>>l>>r>>k;
    //     cout<<uniques[query(prefixes[r],prefixes[l-1],k)]<<endl;
    // }

    return 0;
}