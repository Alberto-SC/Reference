#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
// #define int long long

/**
 * Author: Alberto Silva, theory and some code from CP algorithms 
 * Date: 2023-02-3
 * Source: CP algorithms
 * Description: A short self-balancing tree. It acts as a
 *  sequential container with log-time splits/joins, and
 *  is easy to augment with additional data. this version is a full binary search tree different from 
 * cp algorithms, this allows to get other usefull data like order of key kth sum etc. 
 * Time: $O(\log N)$
 * Status: Tested [Codeforces - 1791] except the function sum_to_key
*/



#define ll long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

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
 

// Ignore from here

signed main(){__
    int T = 1,n = 5,c;
    clean();
    vector<int> nums = {1,2,3,4,5,1,2,3,4,5,9,8,10};
    // for(auto &c:nums)cin>>c;

    for(int i = 0;i<nums.size();i++)
        insert(nums[i]);
    
    print(root);

    cout<<endl;
    // cout<<order_of_key(root,1)<<endl;;
    // cout<<order_of_key(root,2)<<endl;;
    // cout<<order_of_key(root,3)<<endl;;
    cout<<sum_to_key(root,1)<<endl;;
    cout<<sum_to_key(root,2)<<endl;;
    cout<<sum_to_key(root,3)<<endl;;
    cout<<sum_to_key(root,4)<<endl;;
    cout<<sum_to_key(root,5)<<endl;;
    cout<<sum_to_key(root,6)<<endl;;
    cout<<sum_to_key(root,7)<<endl;;
    cout<<sum_to_key(root,8)<<endl;;
    cout<<sum_to_key(root,9)<<endl;;
    cout<<sum_to_key(root,10)<<endl;;

    // cout<<getKth(root,1)<<endl;;
    // cout<<getKth(root,2)<<endl;;
    // cout<<getKth(root,3)<<endl;;
    // cout<<getKth(root,4)<<endl;;
    // cout<<getKth(root,5)<<endl;;
    // cout<<getKth(root,6)<<endl;;
    // cout<<getKthSum(root,1)<<endl;;
    // cout<<getKthSum(root,2)<<endl;;
    // cout<<getKthSum(root,3)<<endl;;
    // cout<<getKthSum(root,4)<<endl;;
    // cout<<getKthSum(root,5)<<endl;;
    // cout<<getKthSum(root,6)<<endl;;

    // cout<<getCountUntilSum(root,1)<<endl;
    // cout<<getCountUntilSum(root,2)<<endl;
    // cout<<getCountUntilSum(root,3)<<endl;
    // cout<<getCountUntilSum(root,4)<<endl;
    // cout<<getCountUntilSum(root,5)<<endl;
    // cout<<getCountUntilSum(root,6)<<endl;
    // cout<<getCountUntilSum(root,7)<<endl;
    // cout<<getCountUntilSum(root,8)<<endl;
    // cout<<getCountUntilSum(root,9)<<endl;
    // cout<<getCountUntilSum(root,10)<<endl;
    // cout<<getCountUntilSum(root,11)<<endl;
    // cout<<getCountUntilSum(root,12)<<endl;
    return 0;
}