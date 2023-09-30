#include <bits/stdc++.h>
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

using namespace std;


#define cerr(s) cerr << "\033[48;5;203m\033[38;5;15m" << s << "\033[0m" // exclude-line
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<> dis(numeric_limits<int>::min(), numeric_limits<int>::max()) ;


struct Treap{
    Treap *l  = NULL,*r = NULL;
    int p,sz = 1,val,sum = 0,mn = 1e9;
    int rev = 0, lazySum  = 0,lazyReplace = 0;
    int sumPend  = 0,ReplacePend = 0;
    Treap(int v ,int prior = dis(rng)):val(v),p(prior){}
};
Treap *root = NULL;
void update(Treap *T){
    if (!T) return;
    T->sz = 1;
    T->sum = T->val;
    T->mn = T->val;    
    if (T->l) {
      T->sz += T->l->sz;
      T->sum += T->l->sum;
      T->mn = min(T->mn,T->l->mn);
    }
    if (T->r) {
      T->sz += T->r->sz;
      T->sum += T->r->sum;
      T->mn = min(T->mn,T->r->mn);
    }
}

void applyRev(Treap *T){
    if(!T)return;
    T->rev^=1;
    swap(T->l,T->r);
}

void applySum(Treap *T,int x){
    if(!T)return;
    T->val+=x;
    T->mn+=x;
    T->sumPend+=x;
    T->lazySum = 1;
    T->sum+=x*T->sz;

}
void applyReplace(Treap *T,int x){
    if(!T)return;
    T->val=x;
    T->mn=x;
    T->ReplacePend=x;
    T->lazyReplace = 1;
    T->sum=x*T->sz;
}
void lazy(Treap *T){
    if(!T)return;
    if(T->rev){
        applyRev(T->l);
        applyRev(T->r);
        T->rev = 0;
    }
    if(T->lazySum){
        applySum(T->l,T->sumPend);
        applySum(T->r,T->sumPend);
        T->lazySum = 0;
        T->sumPend = 0;
    }
    if(T->lazyReplace){
        applyReplace(T->l,T->ReplacePend);
        applyReplace(T->r,T->ReplacePend);
        T->lazyReplace = 0;
        T->ReplacePend = 0;
    }
}
pair<Treap*,Treap*> split(Treap *T,int idx,int cont = 0){
    if(!T)return {NULL,NULL};
    lazy(T);
    Treap *L, *R;
    int idxt = cont + (T->l?T->l->sz:0);
    if(idx<idxt)
        tie(L,T->l) = split(T->l,idx,cont),R = T;
    else  
        tie(T->r,R) = split(T->r,idx,idxt+1),L = T; 
    update(T);
    return {L,R};
}

void insert(Treap *&T,Treap *v,int x, int cnt) {
    lazy(T);
    int idxt = T ? cnt + (T->l ? T->l->sz : 0) : 0;
    if (!T) T = v;
    else if (v->p > T->p)
        tie(v->l, v->r) = split(T, x, cnt), T = v;
    else if (x < idxt) insert(T->l, v, x, cnt);
    else insert(T->r, v, x, idxt + 1);
    update(T);
}

void insert(int e, int i) {
    insert(root, new Treap(e), i-1, 0);
}


Treap *merge(Treap *a,Treap *b){
    lazy(a),lazy(b);
    Treap *T;
    if(!a || !b)T = a?a:b;
    else if(a->p > b->p)
        a->r = merge(a->r,b),T = a;
    else b->l = merge(a,b->l),T = b;
    update(T);
    return T;
}


void erase(Treap *&T,int x ,int cnt = 0){
    if(!T)return;
    lazy(T);
    int left = cnt+(T->l? T->l->sz:0);
    if(left == x)T = merge(T->l,T->r);
    else if(x<left)erase(T->l,x,cnt);
    else erase(T->r,x,left+1);
    update(T);
}

void print(Treap *t) {
    if (!t) return;
    lazy(t);
    print(t->l);
    print(t->r);
}
void push_back(int e) {
    root = merge(root, new Treap(e));
}


void op(int l,int r, function<void(Treap *T)> f){
    Treap *a,*b,*c;
    tie(a,b) = split(root,l-1);
    tie(b,c) = split(b,r-l);
    f(b);
    root = merge(a, merge(b,c));
}

void reverse(int l,int r){
    op(l,r,[&](Treap *T){applyRev(T);});
}

void rotate(int l,int r,int k){
    op(l,r,[&](Treap *T){
        Treap *l,*r;
        k%=T->sz;
        tie(l,r) = split(T,T->sz-k-1);
        T = merge(r,l);
    });
}

void add(int l,int r,int x){
    op(l,r,[&](Treap *T){
        applySum(T,x);
    });
}

void replace(int l,int r,int x){
    op(l,r,[&](Treap *T){
        applyReplace(T,x);
    });
}

int get_sum(int l,int r){
    int ans;
    op(l,r,[&](Treap *T){
        ans = T->sum;
    });
    return ans;
}

int get_min(int l,int r){
    int mn;
    op(l,r,[&](Treap *T){
        mn = T->mn;
    });
    return mn;
}

signed main(){__
    int T = 1,n,m,q;
    while(T--){
        cin>>n>>m>>q;
        for(int i = 0;i<n;i++)
            insert(i,i);

        while(m--){
            int l,r;
            cin>>l>>r;
            l--,r--;
            reverse(l,r);
        }
        for(int i = 0;i<q;i++){
            int idx;
            cin>>idx;
            idx--;
            cout<<get_min(idx,idx)+1<<" ";
        }
        cout<<endl;
    }
    return 0;
}
