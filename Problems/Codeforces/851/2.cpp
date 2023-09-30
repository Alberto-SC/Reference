#include <bits/stdc++.h>
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;

typedef struct item *pitem;
struct item {
	ll pr,key,cnt; ll val,mx;
	pitem l,r;
	item(ll key, ll val):key(key),pr(rand()),cnt(1),l(0),r(0),val(val),mx(mx) {}
};
ll cnt(pitem t){return t?t->cnt:0;}
ll val(pitem t){return t?t->val:0;}
ll mx(pitem t){return t?t->mx:0;}
void upd_cnt(pitem t){
	if(t){
		t->cnt=cnt(t->l)+cnt(t->r)+1;
		t->mx=max({mx(t->l),mx(t->r),t->val});
	}
}
void split(pitem t, ll key, pitem& l, pitem& r){ // l: < key, r: >= key
	if(!t)l=r=0;
	else if(key<t->key)split(t->l,key,l,t->l),r=t;
	else split(t->r,key,t->r,r),l=t;
	upd_cnt(t);
}
void insert(pitem& t, pitem it){
	if(!t)t=it;
	else if(it->pr>t->pr)split(t,it->key,it->l,it->r),t=it;
	else insert(it->key<t->key?t->l:t->r,it);
	upd_cnt(t);
}
void merge(pitem& t, pitem l, pitem r){
	if(!l||!r)t=l?l:r;
	else if(l->pr>r->pr)merge(l->r,l->r,r),t=l;
	else merge(r->l,l,r->l),t=r;
	upd_cnt(t);
}

int main(){FIN;
	int n; cin>>n;
	vector<ll> a(n+1);
	fore(i,0,n) cin>>a[i];
	for(int i=n-2;i>=0;i--) a[i]+=a[i+1];
	
	pitem rt=0;
	
	vector<int> dp(n+1);
	for(int i=n-1;i>=0;i--){
		insert(rt, new item(a[i+1], i+dp[i+1]));
		
		pitem l,r;
		split(rt, a[i], l, r);
		  
    cout<<"I: "<<i<<endl;

		if(cnt(l)){
			dp[i]=mx(l)-i+1;
	    cout<<mx(l)<<endl;
    }
		    
    cout<<dp[i]<<endl;
  
	  dp[i]=max(dp[i], dp[i+1]);
		
		
		merge(rt,l,r);
	}
	
	int ans=0;
	for(auto x:dp) ans=max(ans,x);
	cout<<ans<<"\n";
	
}
