#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

using namespace std;

#define ll int 

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rand(int l, int r){
  uniform_int_distribution<int> ludo(l, r); return ludo(rng);
}
#define PT Treap *

struct Treap {
	int pr,key,sz; 
    ll sum;
	Treap *l = NULL,*r = NULL;
	Treap(int key):key(key),pr(rand(0,1e9)),sz(1),l(0),r(0),sum(key) {}
};


PT root = NULL;

int sz(PT T){return T?T->sz:0;}
ll sum(PT T){return T?T->sum:0ll;}

void update(PT T){
    if(!T)return ;
    T->sz=sz(T->l)+sz(T->r)+1;
    T->sum=sum(T->l)+sum(T->r)+T->key;
}

void split(PT T, int key, PT& l, PT& r){ // l: <= key, r: > key
	if(!T)l=r=NULL;
	else if(T->key<=key)split(T->r,key,T->r,r),l=T;
	else split(T->l,key,l,T->l),r=T;
	update(T);
}

void insert(PT& T,PT v){
	if(!T)T=v;
    else if(v->pr>T->pr)split(T,v->key,v->l,v->r),T=v;
    else insert(v->key<=T->key?T->l:T->r,v);
	update(T);
}

void insert(int key){
    insert(root,new Treap(key));
}

void merge(PT& T, PT l, PT r){
	if(!l||!r)T=l?l:r;
	else if(l->pr>r->pr)merge(l->r,l->r,r),T=l;
	else merge(r->l,l,r->l),T=r;
	update(T);

}
void erase(PT& T, int key){
	if(T->key==key)merge(T,T->l,T->r);
	else erase(key<T->key?T->l:T->r,key);
	update(T);
}

void print(PT T){
    if(!T)return;
    print(T->l);
    cout<<"("<<T->key<<","<<T->sz<<","<<T->sum<<") ";
    print(T->r);
    update(T);
}

// Number of elements less or equal than x
int order_of_key(PT T,ll x,int cont = 0){
    if(!T)return cont;
    if(T->key == x)return cont+sz(T->l)+1;
    if(x<T->key)return order_of_key(T->l,x,cont);
    return order_of_key(T->r,x,sz(T->l)+cont+1);
}

// Get the sum of all y<=x
// /- Seems that not work  -/
ll sum_to_key(PT T,ll x,int s = 0){
    if(!T)return s;
    if(T->key == x)return sum(T->l)+s+x;
    if(x<T->key)return sum_to_key(T->l,x,s);
    return sum_to_key(T->r,x,sum(T->l)+s+T->key);
}

// Get the kth element, one indexed, the order is non decreseal
ll getKth(PT T,int idx){
    if(!T)return -1;
    if(idx == 0 || sz(T->l)+sz(T->r)==0)return T->key;
    if(sz(T->l)+1 == idx)return T->key;
    if(sz(T->l)>=idx)return getKth(T->l,idx);
    return getKth(T->r,idx-(sz(T->l)+1));
}

// get the sum of the first kth elements 
ll getKthSum(PT T,int idx,ll s = 0){
    if(!T)return s;
    if(idx == 0 || sz(T->l)+sz(T->r)==0)return s+T->key;
    if(sz(T->l)+1 == idx)return T->key +s+sum(T->l);
    if(sz(T->l)>=idx)return getKthSum(T->l,idx,s);
    return getKthSum(T->r,idx-(sz(T->l)+1),s+sum(T->l)+T->key);
}

// Return the maximum k such sum of kth smallest elements is les or equal than x
ll getCountUntilSum(Treap *T ,ll x){
	if(!T)return 0;
    if(T->l && T->l->sum >x)return getCountUntilSum(T->l,x);
    ll ans = sz(T->l);
    if(sum(T->l)+T->key <=x)ans +=1+getCountUntilSum(T->r,x-(sum(T->l)+T->key));
    return ans;
}

void clean(PT T){
    if(!T)return;
    clean(T->l);
    clean(T->r);
    delete T;
}
void clean(){
    clean(root);
    root = NULL;
}

ll f(ll l,ll r,ll k,ll sum ,int sz){
	ll len = (r-l)+1;
  ll need = max(0,k-len);
		
	ll cnt = getCountUntilSum(root,sum-need);
	ll used = sz-cnt;
	ll best = ((used+1)*2)+r;
  return best;
}

signed main(){__
    int T,n,k;
    cin>>T;
    while(T--){
        cin>>n>>k;
				clean();
        vector<pair<int,int>> v(n);
				for(int i = 0;i<n;i++)cin>>v[i].first;
				for(int i = 0;i<n;i++)cin>>v[i].second;

				ll sum = 0;
				ll ans = 2e9;
				for(int i = 0;i<n;i++){
						ll len = (v[i].second-v[i].first)+1;
						
						if(sum+len<k){
								sum+=len;
								insert(len);
								continue;
						}
						
						ll l = v[i].first +max(0,(k-sum)-1);
						ll r = min(v[i].second,(v[i].first+k)-1);
						
						int first = f(v[i].first,l,k,sum,i);
						
						int ones = order_of_key(root,1);

						int second = 2e9;
						cout<<v[i].first+ones-1<<endl;
						if(((v[i].first+ones)-1)>=l)second = f(v[i].first,min(r,v[i].first+ones-1),k,sum,i);

						ans = min({ans,first,second});
				

						/* for(int j = l;j<=r;j++){ */
								/* cout<<f(v[i].first,j,k,sum,i)<<" "; */
						/* } */
						/* cout<<endl; */

						sum+=len;
						insert(len);
				}
				if(ans == 2e9)cout<<-1<<endl;
				else cout<<ans<<endl;
    }
    return 0;    
}
