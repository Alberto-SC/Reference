#include <bits/stdc++.h>
using namespace std;
vector<int> st;
vector<int> lazy;
vector<int> zeros;
typedef long long int lli;
const int maxn = 3000007;
#define print(A) for(auto c:A)cout<<c<<" ";cout<<endl;

// SOLVES the number of good segments in a subsegment of a permutation of size n 
// good segment is a segment such if that is sorted all elements are consecutive in that segment 

void propagate(int v,int l,int r){
	if(lazy[v]== 0)return;
	st[v] +=lazy[v];
    if(st[v]!= 0)zeros[v] = 0;
	if(l != r){
		lazy[v<<1]+=lazy[v];
		lazy[v<<1|1]+=lazy[v];
	}
	lazy[v] = 0;
}
void update(int v ,int sl ,int sr ,int l ,int  r,int val){
	if(l> sr || r<sl|| sr<sl)return;
	propagate(v,sl,sr);
	if(sl>= l && sr<= r){
		lazy[v] += val;
		propagate(v,sl,sr);
	}
	else{
		int mid = (sl+sr)>>1;
		update(v<<1,sl,mid,l,r,val);
		update(v<<1|1,mid+1,sr,l,r,val);
		propagate(v<<1,sl,mid);
		propagate(v<<1|1,mid+1,sr);
		int val = min(st[v<<1],st[v<<1|1]);
		st[v] = val;
		zeros[v]  = (st[v<<1]== val?zeros[v<<1]:0) + (st[v<<1|1] == val?zeros[v<<1|1]:0);
	}
}

int query(int v,int sl ,int sr ,int l ,int r){
	if(l>sr || r<sl || sr<sl)return 0;
	propagate(v,sl,sr);
	if(sl >= l && sr <= r){
		if(st[v]== 0)return zeros[v];
		return 0;
	}
	int mid = (sl+sr)>>1;
	return query(v<<1,sl,mid,l,r)+query(v<<1|1,mid+1,sr,l,r);
}

void printst(int n){
    for(int i = 0;i<n;i++)  
        cout<<query(1,0,n-1,i,i)<<" ";
    cout<<endl;
}

int main(){
	int n,a,b;
	cin>>n;
	st.resize(4*n);
	lazy.resize(4*n);
	zeros.assign(4*n,1);
	vector<int> nums(n);
    char x;
	for(int i = 0;i<n;i++){
		cin>>x;
        update(1,0,n-1,i,i,0);
		nums[i] = x-'0';
	}	
	lli ans = 0;
	for(int i = 0;i<n;i++){
        update(1,0,n-1,0,i,nums[i]);
        update(1,0,n-1,0,i,-1);
        cout<<query(1,0,n-1,0,i)<<endl;
		ans+= query(1,0,n-1,0,i);
        printst(n);
        print(zeros);
	}	
	cout<<ans<<endl;
	return 0;
}
