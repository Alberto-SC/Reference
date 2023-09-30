#include <bits/stdc++.h>
using namespace std;
vector<int> st;
vector<int> lazy;
vector<int> zeros;
typedef long long int lli;
const int maxn = 3000007;
#define print(A) for(auto c:A)cout<<c<<" ";cout<<endl;

void propagate(int v,int l,int r){
	if(lazy[v]== 0)return;
	st[v] +=lazy[v];
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

int main(){
	int n,a,b;
	cin>>n;
	st.resize(4*n);
	lazy.resize(4*n);
	zeros.assign(4*n,1);
	vector<int> nums(n);
	for(int i = 0;i<n;i++){
		cin>>a>>b;
		nums[a-1] = b;
	}	
	vector<int> mx = {-1},mn = {-1};
	lli ans = 0;
	for(int i = 0;i<n;i++){
		while(mx.back()!= -1 && nums[mx.back()]< nums[i]){
			int x = mx.back(); 
			mx.pop_back();
			update(1,0,n-1,mx.back()+1,x,nums[i]-nums[x]);
		}
		mx.push_back(i);
		while(mn.back()!= -1 && nums[mn.back()]> nums[i]){
			int x = mn.back();
			mn.pop_back();
			update(1,0,n-1,mn.back()+1,x,nums[x]-nums[i]);
		}
		mn.push_back(i);
		ans+= query(1,0,n-1,0,i);
		update(1,0,n-1,0,i,-1);
	}	
	cout<<ans<<endl;
	return 0;
}