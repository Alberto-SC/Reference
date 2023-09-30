#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;
const int maxn = 7000007;
#define endl '\n'
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
int L[maxn],R[maxn],st[maxn];

int idx;
int new_leaf(int val){
    int p = ++idx;
    L[p] = 0;
    R[p] = 0;
    st[p] = val;
    return p;
}
int new_parent(int l,int r){
    int p = ++idx;
    L[p] = l;
    R[p] = r;
    st[p] = st[l]+st[r];
    return p;
}

int M;
int build(vector<int> &A,int l= 0,int r =M){
    if(l == r)return new_leaf(A[l]);
    else{
        int m = (l+r)>>1;
        return new_parent(build(A,l,m),build(A,m+1,r));
    }

}
int update(int pos,int val,int p,int l = 0,int r = M){
    if(l == r)return new_leaf(st[p]+val);
    else{
        int m = (l+r)>>1;
        if(pos<=m)
            return new_parent(update(pos,val,L[p],l,m),R[p]);
        else 
            return new_parent(L[p],update(pos,val,R[p],m+1,r));
    }
}


int query(int l,int r ,int p,int sl = 0,int sr = M){
    if(sl>r || sr<l ||sl>sr)return 0;
    if(sl>=l && sr<=r)return st[p];
    int m =(sl+sr)>>1;
    return query(l,r,L[p],sl,m)+query(l,r,R[p],m+1,sr);
}


int main(){__
    int n,q,L,R,A,B;
    cin>>n>>M>>q;
    vector<int> nums(n);
    for(auto &c:nums)cin>>c;
    vector<int> pref;
    vector<int> zeros(M+1,0);
    pref.push_back(build(zeros));
    for(int i = 0;i<n;i++)
        pref.push_back(update(nums[i],1,pref.back()));
    int ans = 0;
    for(int i = 0;i<q;i++){
        cin>>L>>R>>A>>B;
        int l,r,a,b;
        (l = (L+ans)%n)++;
        (r = (R+ans)%n)++;
        (a = (A+ans)%M)++;
        (b = (B+ans)%M)++;
        if(l>r)swap(l,r);
        if(a>b)swap(a,b);
        int x = query(0,b,pref[r]);
        x-=query(0,a-1,pref[r]);
        int y = query(0,b,pref[l-1]);
        y-= query(0,a-1,pref[l-1]);
        ans = x-y;
        cout<<ans<<endl;
    }       
    return 0;
}