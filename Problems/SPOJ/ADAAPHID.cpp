#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<> dis(numeric_limits<int>::min(), numeric_limits<int>::max());
#define endl '\n';
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
struct Treap{
    Treap *l = NULL,*r = NULL;
    lli val,key,p,sum;
    Treap(lli val,lli key,lli p = dis(rng)):val(val),key(key){}
};

void update(Treap *&T){
    if(!T)return;
    T->sum = T->val;
    if(T->l)
        T->sum+=T->l->sum;
    if(T->r)
        T->sum+=T->r->sum;
}

pair<Treap*,Treap*> split(Treap* &T,lli x){
    Treap *l,*r;
    if(!T)return {NULL,NULL};
    else if(x<T->key)
        tie(l,T->l) = split(T->l,x),r = T;
    else 
        tie(T->r,r) = split(T->r,x),l = T;
    update(T);    
    return {l,r};
}

Treap * merge(Treap *&l,Treap*&r){
    Treap *T;
    if(!l || !r)T = l?l:r;
    else if(l->p>r->p)
        l->r = merge(l->r,r),T = l;
    else 
        r->l = merge(l,r->l),T = r;
    update(T);
    return T;
}

void insert(Treap *&T,Treap *&v){
    if(!T)
        T = v;
    else if(v->p>T->p)
        tie(v->l,v->r) = split(T,v->key),T = v;
    else 
        insert(v->key<=T->key?T->l:T->r,v);
    update(T);
}

void print(Treap *T){
    if(!T)return;
    print(T->l);
    cout<<"("<<T->val<<","<<T->key<<") ";
    print(T->r);
    update(T);
}

lli sum(Treap *&T,lli x){
    Treap *l,*r;
    tie(l,r) = split(T,x);
    // print(l);
    // cout<<endl; 
    // print(r);
    // cout<<endl;
    lli ans = l?l->sum:0;
    T = merge(l,r);
    return ans;
}


int main(){__
    lli n,a,v;
    cin>>n;
    Treap *root = NULL;
    lli l = 0;
    for(lli i = 0;i<n;i++){
        cin>>a>>v;
        a^=l;
        v^=l;
        // cout<<a<<" "<<v<<endl;
        lli ans = v;
        ans+= sum(root,a);
        Treap *x = new Treap(v,a);
        insert(root,x);
        // print(root);
        cout<<a<<" "<<ans<<endl;
        l = ans;
    }
    return 0;
}