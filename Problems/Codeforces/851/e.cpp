#include <bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

const int mod = 1e9+7;

#define ll long long 

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rand(int l, int r){
  uniform_int_distribution<int> ludo(l, r); return ludo(rng);
}

#define PT Treap *

struct Treap {
	ll pr,key,sz,val; 
  ll sum,mx;
	Treap *l = NULL,*r = NULL;
	Treap(ll key,ll val):key(key),val(val),mx(val),pr(rand(0,1e9)),sz(1),sum(key) {}
};


PT root = NULL;

int sz(PT T){return T?T->sz:0;}
ll sum(PT T){return T?T->sum:0ll;}
ll mx(PT T){return T?T->mx:0ll;}

void update(PT T){
    if(!T)return ;
    T->sz=sz(T->l)+sz(T->r)+1;
    T->sum=sum(T->l)+sum(T->r)+T->key;
    T->mx = max({mx(T->l),mx(T->r),(ll)T->val});
}

void split(PT T, ll key, PT& l, PT& r){ // l: <= key, r: > key
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

void insert(ll key,ll val){
    insert(root,new Treap(key,val));
}

void merge(PT& T, PT l, PT r){
	if(!l||!r)T=l?l:r;
	else if(l->pr>r->pr)merge(l->r,l->r,r),T=l;
	else merge(r->l,l,r->l),T=r;
	update(T);

}
void erase(PT& T, ll key){
	if(T->key==key)merge(T,T->l,T->r);
	else erase(key<T->key?T->l:T->r,key);
	update(T);
}

void print(PT T){
    if(!T)return;
    print(T->l);
    cout<<"("<<T->key<<","<<T->sz<<","<<T->mx<<") ";
    print(T->r);
    update(T);
}

// Number of elements less or equal than x
int order_of_key(PT T,int x,int cont = 0){
    if(!T)return cont;
    if(T->key == x)return cont+sz(T->l)+1;
    if(x<T->key)return order_of_key(T->l,x,cont);
    return order_of_key(T->r,x,sz(T->l)+cont+1);
}

// Get the sum of all y<=x
// /- Seems that not work  -/
int sum_to_key(PT T,int x,int s = 0){
    if(!T)return s;
    if(T->key == x)return sum(T->l)+s+x;
    if(x<T->key)return sum_to_key(T->l,x,s);
    return sum_to_key(T->r,x,sum(T->l)+s+T->key);
}

// Get the kth element, one indexed, the order is non decreseal
int getKth(PT T,int idx){
    if(!T)return -1;
    if(idx == 0 || sz(T->l)+sz(T->r)==0)return T->key;
    if(sz(T->l)+1 == idx)return T->key;
    if(sz(T->l)>=idx)return getKth(T->l,idx);
    return getKth(T->r,idx-(sz(T->l)+1));
}

// get the sum of the fist kth elements 
int getKthSum(PT T,int idx,int s = 0){
    if(!T)return s;
    if(idx == 0 || sz(T->l)+sz(T->r)==0)return s+T->key;
    if(sz(T->l)+1 == idx)return T->key +s+sum(T->l);
    if(sz(T->l)>=idx)return getKthSum(T->l,idx,s);
    return getKthSum(T->r,idx-(sz(T->l)+1),s+sum(T->l)+T->key);
}

// Return the maximum k such sum of kth smallest elements is les or equal than x
int getCountUntilSum(Treap *T ,int x){
	if(!T)return 0;
    if(T->l && T->l->sum >x)return getCountUntilSum(T->l,x);
    int ans = sz(T->l);
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


signed main(){__
  int T =1 ,n;
  while(T--){
    cin>>n;
    vector<int> nums(n);
    for(auto &c:nums)cin>>c;
    
    vector<ll> ac(n+1);
    ac[n-1] = nums[n-1];

    for(int i = n-2;i>=0;i--)
      ac[i] = nums[i]+ac[i+1];
    
    vector<int> dp(n+1);
    
    for(int i = n-1;i>=0;i--){
        
      insert(ac[i+1],i+dp[i+1]);
      PT L;
      PT R;

      split(root,ac[i],L,R);
        
    
      if(sz(L)){
        dp[i] = mx(L)-i+1;
        cout<<mx(L)<<endl;
      }
      cout<<i<<" "<<dp[i]<<endl;
      dp[i] = max(dp[i],dp[i+1]);
      merge(root,L,R); 
    }
    cout<<dp[0]<<endl;
  }
  return 0;
}

