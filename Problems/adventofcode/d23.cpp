#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define cerr(s) cerr << "\033[48;5;203m\033[38;5;15m" << s << "\033[0m"
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<> dis(numeric_limits<int>::min(), numeric_limits<int>::max());

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
    cout<<t->val<<" ";
    // cerr(to_string(t->val));
    // cerr(" ");
    // cout << t->val<<" ";
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
void print2(){
    for(int i = 0;i<40;i++){
        cerr(to_string(get_sum(i,i)));
        cerr(" ");
    }
    cout<<endl;
    int n = 1000000;
    for(int i = n-20;i<n;i++){
        cerr(to_string(get_sum(i,i)));
        cerr(" ");
    }
    cout<<endl;
}

void find_one(){
    int idx = 0;
    int n = 1000000;
    for(int i = 0;i<n;i++){
        if(get_sum(i,i) == 1){
            idx = i;
            break;
        }
        if(get_sum((n-1)-i,(n-1)-i) == 1){
            idx = n-i;
            break;
        }
    }
    cout<<get_sum(((idx-1)+n)%n,((idx-1)+n)%n)<<" "<<get_sum((idx+1)%n,(idx+1)%n)<<endl;
}



int main(){
    string s;
    cin>>s;
    int n = s.size();
    int mx = 0;
    for(int i = 0;i<n;i++){
        mx = max(mx,s[i]-'0');
        insert(s[i]-'0',i);
    }
    clock_t begin = clock();
    for(int i = n;i<1000000;i++){
        insert(mx++,i);
    }
    n = 1000000;
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    cout<<fixed<<setprecision(6)<<time_spent<<endl;
    int last = 0,last2 = 240000,last3 = 430000;
    clock_t begin2 = clock();
    for(int i = 0;i<10000000;i++){
        cout<<"I: "<<i<<endl;
        vector<int> to_push;
        int current = get_sum(i%n,i%n);
        set<int> pick;
        int offset = 0;
        for(int cont = 0;cont<3;cont++){
            if((i%n)+1<n-cont){
                int value = get_sum((i%n)+1,(i%n)+1);
                to_push.push_back(value);
                pick.insert(value);
                erase(root,(i%n)+1);
            }
            else{
                offset++;
                int value = get_sum(0,0);
                to_push.push_back(value);
                pick.insert(value);
                erase(root,0);
            }
        }
        int dest = current-1;
        if(dest == 0)dest = mx;
        while(pick.count(dest)){
            dest--;   
            if(dest == 0)dest = mx;
        }
        int idx;
        // cout<<last<<" "<<last2<<endl; 
        for(int j = 0;j<n;j++){
            if(get_sum((last+j)%(n-3),(last+j)%(n-3))==dest){idx = (last+j)%(n-3);break;}
            if(get_sum(((last-j)+(n-3))%(n-3),((last-j)+(n-3))%(n-3))==dest){idx = ((last-j)+(n-3))%(n-3);break;}
            if(get_sum((last2+j)%(n-3),(last2+j)%(n-3))==dest){idx = (last2+j)%(n-3);break;}
            if(get_sum(((last2-j)+(n-3))%(n-3),((last2-j)+(n-3))%(n-3))==dest){idx = ((last2-j)+(n-3))%(n-3);break;}
            if(get_sum((last3+j)%(n-3),(last3+j)%(n-3))==dest){idx = (last3+j)%(n-3);break;}
            if(get_sum(((last3-j)+(n-3))%(n-3),((last3-j)+(n-3))%(n-3))==dest){idx = ((last3-j)+(n-3))%(n-3);break;}
        }
        assert(get_sum(idx,idx)==dest);
        cout<<idx<<endl;
        last = idx;
        for(int cont = 0;cont<3;cont++)
            insert(to_push[2-cont],idx+1);
        if(idx<(i%n))rotate(0,n-1,(n-3)+offset);
        // find_one();
    }       
    print(root);
    cout<<endl;
    clock_t end2 = clock();
    double time_spent2 = (double)(end2 - begin2) / CLOCKS_PER_SEC;
    cout<<fixed<<setprecision(6)<<time_spent2<<endl;
    return 0;
}  


// 624397158