#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<> dis(numeric_limits<int>::min()+10, numeric_limits<int>::max()-10);


// TESTED IN [SPOJ - ADACROP]
struct Treap{
    Treap *l = NULL,*r = NULL;
    int key,p,sz = 1;
    Treap(int key,int p =rand()):key(key),p(p){}
};
Treap *root = NULL;

void update(Treap *T){
    if(!T)return;
    T->sz = 1;
    if(T->l)T->sz+=T->l->sz;
    if(T->r)T->sz+=T->r->sz;
}

pair<Treap*,Treap*> split(Treap *T,int x){
    Treap *l,*r;
    if(!T)
        return {NULL,NULL};
    if(x<T->key)
        tie(l,T->l) = split(T->l,x),r = T;
    else 
        tie(T->r,r) = split(T->r,x),l = T;
    update(T);
    return {l,r};
}

Treap* merge(Treap *a,Treap *b){
    Treap *T;
    if(!a || !b)T = a?a:b;
    else if(a->p >b->p)a->r = merge(a->r,b),T = a;
    else b->l = merge(a,b->l),T = b;
    update(T);
    return T;
}


void insert(Treap *&T,Treap *v){
    // cout<<"HI"<<endl;
    if(!T)
        T = v;
    else if(v->p>T->p)
        tie(v->l,v->r) = split(T,v->key),T=v;
    else 
        insert(v->key<T->key?T->l:T->r,v);
    update(T);
}

void insert(int x){
    insert(root,new Treap(x));
}


void erase(Treap *&T,int key){
    if(!T)return;
    if(T->key == key)
        T = merge(T->l,T->r);
    else erase((key<T->key)?T->l:T->r,key);
    update(T);
}

void print(Treap *T){
    if(!T)return ;
    print(T->l);
    cout<<"("<<T->key<<","<<T->sz<<") ";
    print(T->r);
    update(T);
}

int order_of_key(Treap *T,int x,int cont = 0){
    if(!T)return cont;
    else if(T->key == x)return T->l?T->l->sz+cont:cont;
    else if(x<T->key)return order_of_key(T->l,x,cont);
    else return order_of_key(T->r,x,cont+(T->l?T->l->sz+1:1));
}



Treap *unite(Treap *l,Treap *r){
    if(!l || !r) return r?r:l;
    if(l->p <r->p)swap(l,r);
    Treap *lt,*rt;
    tie(lt,rt) = split(r,l->key);
    l->l = unite(l->l,lt);
    l->r = unite(l->r,rt);
    return l;
}

int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(auto &c:nums)cin>>c;
    for(int i  = 0;i<n;i++)
        insert(nums[i]);
    
    print(root);
    erase(root,2);
    cout<<endl;
    print(root);
    insert(8);
    insert(2);
    cout<<endl;
    print(root);
    cout<<endl;
    erase(root,1);
    print(root);
    
    cout<<endl<<order_of_key(root,9)<<endl;
    erase(root,8);
    insert(3);
    print(root);
    cout<<endl;
    cout<<order_of_key(root,3)<<endl;
    return 0;
}