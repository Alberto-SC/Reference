#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
//_________Segment Tree___________//
/*
	[Tested Timus 1141,1204]
*/
int n;

//Iterative Segment tree
// struct ST {
// 	int mx[(1 << 20) + 1];
// 	inline void upd(int x, int val) {
// 		x += n;
// 		mx[x] = val;
// 		for (; x /= 2; mx[x] = max(mx[x * 2], mx[x * 2 + 1]));
// 	}
// 	inline int fnd(int l, int r) {
// 		int ans = 0;
// 		for (l += n, r += n; l <= r; l = (l + 1) / 2, r = (r - 1) / 2) {
// 			if (l & 1) ans = max(ans, mx[l]);
// 			if (~r & 1) ans = max(ans, mx[r]);
// 		}
// 		return ans;
// 	}
// };
 

vector<lli> st;
void build(vector<lli> &A,int v,int l,int r){
    if(l == r)st[v] = A[l];
    else{
        int m = (l+r)/2;
        build(A,v*2,l,m);
        build(A,v*2+1,m+1,r);
        st[v] = st[v*2] + st[v*2+1];
    }

}
lli query(int v,int sl,int sr,int l,int r){
    if(r<sl || l>sr)return 0;
    if(sl>=l && sr<=r)return st[v];
    int m = (sl+sr)/2;
    return query(v*2,sl,m,l,r)+
    query(v*2+1,m+1,sr,l,r);
}
void update(int v,int sl,int sr,int pos,int val){
    if(sl == sr)st[v] = val;
    else{
        int m = (sl+sr)/2;
        if(pos<=m)
            update(v*2,sl,m,pos,val);
        else    
            update(v*2+1,m+1,sr,pos,val);
        st[v] = st[v*2]+ st[v*2+1];
    }
}
int main(){
    cin>>n;
    vector<lli> nums(n);
    for(auto &c:nums)cin>>c;
    // --------------TEST SEGMENT TREE-------------------
    // st.resize(4*n);
    // build(nums,1,0,n-1);
    // cout<<query(1,0,n-1,2,4)<<endl;
    // update(1,0,n-1,5,20);
    // cout<<query(1,0,n-1,4,5)<<endl;
    return 0;
}