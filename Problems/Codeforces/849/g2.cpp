#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define PT Treap *
struct Treap {
	int pr,key,sz; 
    int sum;
	Treap *l = NULL,*r = NULL;
	Treap(int key):key(key),pr(rng()),sz(1),l(0),r(0),sum(key) {}
};


PT root = NULL;

int sz(PT T){return T?T->sz:0;}
int sum(PT T){return T?T->sum:0ll;}

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

int order_of_key(PT T,int x,int cont = 0){
    if(!T)return cont;
    if(T->key == x)return cont+sz(T->l)+1;
    if(x<T->key)return order_of_key(T->l,x,cont);
    return order_of_key(T->r,x,sz(T->l)+cont+1);
}

int sum_to_key(PT T,int x,int s = 0){
    if(!T)return s;
    if(T->key == x)return sum(T->l)+s+x;
    if(x<T->key)return sum_to_key(T->l,x,s);
    return sum_to_key(T->r,x,sum(T->l)+s+T->key);
}

// one indexed 
int getKth(PT T,int idx){
    if(!T)return 1e16; // not exist;
    if(idx == 0 || sz(T->l)+sz(T->r)==0)return T->key;
    if(sz(T->l)+1 == idx)return T->key;
    if(sz(T->l)>=idx)return getKth(T->l,idx);
    return getKth(T->r,idx-(sz(T->l)+1));
}

int getKthSum(PT T,int idx,int s = 0){
    if(!T)return s;
    if(idx == 0 || sz(T->l)+sz(T->r)==0)return s+T->key;
    if(sz(T->l)+1 == idx)return T->key +s+sum(T->l);
    if(sz(T->l)>=idx)return getKthSum(T->l,idx,s);
    return getKthSum(T->r,idx-(sz(T->l)+1),s+sum(T->l)+T->key);
}

// Return the maximum k such sum of kth smallest elements is less or equal than x
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
    int T = 1,n,c;
    cin>>T;
    while(T--){
        cin>>n>>c;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        clean();
        for(int i = 0;i<n;i++)    
            insert(nums[i]+(min(i+1,n-i)));
        
        int ans = 0;
        for(int i = 0;i<n;i++){
            if(nums[i]+i+1 >c)continue;
            erase(root,nums[i]+(min(i+1,n-i)));

            int l = 0,r = n;
            while(l+1<r){
                int m = (l+r)>>1;
                if(sum_to_key(root,getKth(root,m))<=(c-(nums[i]+i+1)))l = m;
                else r = m;
            }
            ans = max(ans,1+l);
            // ans = max(ans,1+getCountUntilSum(root,c-(nums[i]+i+1)));
            insert(nums[i]+(min(i+1,n-i)));
        }
        cout<<ans<<endl;
    }
    return 0;
}
