#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<> dis(numeric_limits<int>::min(), numeric_limits<int>::max());
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
struct query{
    int x,nw;
};

struct Treap{
    Treap *l = NULL,*r = NULL;
    int key,p,sz = 1;
    Treap(int key,int p =dis(rng)):key(key),p(p){}
};

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

void insert(Treap *&T, int x){
    insert(T,new Treap(x));
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
    cout<<T->key<<" ";
    print(T->r);
    update(T);
}

int order_of_key(Treap *T,int x,int cont = 0){
    // cout<<"HI"<<endl;
    if(!T)return cont;
    else if(T->key == x)return T->l?T->l->sz+cont:cont;
    else if(x<T->key)return order_of_key(T->l,x,cont);
    else return order_of_key(T->r,x,cont+(T->l?T->l->sz+1:1));
}


int main(){__
    int n,m,x,nw;
    cin>>n>>m;
    // mp.reserve(1024);
    // mp.max_load_factor(0.25);
    vector<int> nums(n);
    vector<int> compress;
    for(int i = 0;i<n;i++){
        cin>>nums[i];
        compress.push_back(nums[i]);
        // mp[nums[i]].insert(i);
    }
    vector<query> Q;
    for(int i = 0;i<m;i++){
        cin>>x>>nw;
        Q.push_back({x,nw});
        compress.push_back(nw);
    }
    sort(compress.begin(),compress.end());
    vector<int> unique;
    int last = compress[0];
    unique.push_back(last);
    for(int i = 0;i<compress.size();i++){
        if(compress[i]!= last){
            last = compress[i];
            unique.push_back(last);
        }
    }
    vector<Treap*> mp(unique.size()+10,NULL);
    for(int i = 0;i<n;i++){
        nums[i] = lower_bound(unique.begin(),unique.end(),nums[i])-unique.begin();
        insert(mp[nums[i]],i);
    }
    // for(auto c:nums)cout<<c<<" ";
    // cout<<endl;
    // print(mp[0]);    
    // cout<<"HI"<<endl;
    for(int i = 0;i<m;i++){
        x = Q[i].x, nw = Q[i].nw;
        nw = lower_bound(unique.begin(),unique.end(),nw)-unique.begin();
        // cout<<nw<<" "<<x<<endl;
        // print(mp[nw]);
        // cout<<endl;
        // cout<<endl;
        // int z = order_of_key(mp[nw],x);
        cout<<order_of_key(mp[nw],x)<<endl;
        // cout<<z<<endl;
        erase(mp[nums[x]],x);
        // cout<<"ERASE"<<endl;
        insert(mp[nw],x);
        nums[x] = nw;
        // for(auto c:nums)cout<<c<<" ";
        // cout<<endl;
    }
    return 0;
}