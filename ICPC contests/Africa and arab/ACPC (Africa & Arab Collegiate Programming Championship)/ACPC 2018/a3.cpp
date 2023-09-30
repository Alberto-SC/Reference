#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<> dis(numeric_limits<int>::min()+10, numeric_limits<int>::max()-10);
const int maxn = 100007;
vector<int> graph[maxn];
struct Treap{
    Treap *l = NULL,*r = NULL;
    int key,p,sz = 1;
    Treap(int key,int p =rand()):key(key),p(p){}
};

vector<Treap*> dist;

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

void insert(int x,int u){
    insert(dist[u],new Treap(x));
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
    cout<<T->key<<", ";
    print(T->r);
    update(T);
}

int z[2]= {0,0};

int order_of_key(Treap *&T,int x,int cont = 0){
    if(!T)return cont;
    else if(T->key == x)return T->l?T->l->sz+cont:cont;
    else if(x<T->key)return order_of_key(T->l,x,cont);
    else return order_of_key(T->r,x,cont+(T->l?T->l->sz+1:1));
}

void count(Treap *&A,int u,int x,int who){
    if(u == 43666)
        cout<<"CONTAR "<<u<<endl;
    if(!A)return ;
    count(A->l,u,x,who);
    // cout<<u<<" "<<who<<" "<<dist[u]->sz<<" "<<x-(A->key+1)<<" "<<(A->key+1)<<" "<<order_of_key(dist[u],x-(A->key+1))<<endl;
    z[who]+= (dist[u]->sz)- order_of_key(dist[u],x-(A->key+1));
    if(who==1)A->key++;
    count(A->r,u,x,who);
}


void unite(Treap *&l,Treap *&r){
    if(!l || !r){r?l = r:l = l;return;}
    if(l->p <r->p)swap(l,r);
    Treap *lt,*rt;
    tie(lt,rt) = split(r,l->key);
    unite(l->l,lt);
    unite(l->r,rt);
    // return l;
}

int mx,mn;
// void dfs(int u,int p =-1){
//     cout<<"U: "<<u<<endl;
//     cout<<"CHILDS"<<endl;
//     for(auto v:graph[u]){
//         cout<<v<<" ";
//     }
//     cout<<endl;
//     for(auto v:graph[u]){
//         if(v == p)continue;
//         // cout<<"V: "<<v<<endl;
//         dfs(v,u);
//         // count(dist[v],u,mn,0);
//         // count(dist[v],u,mx+1,1);
//         // unite(dist[u],dist[v]);
//     }
//     cout<<"return U: "<<u<<endl; 
// }

void dfs(int u,int p = -1){
    for(auto v:graph[u]){
        if(v == p)continue;
        count(dist[v],u,mn,0);
        count(dist[v],u,mx+1,1);
        // unite(dist[u],dist[v]);
        dfs(v,u);
    }
}

int main(){
    freopen("awesome.in", "r", stdin);
	int t= 1,n,l,r,u,v;
    cin>>t;
    while(t--){
        cin>>n>>l>>r;
        for(int i = 0;i<n;i++){
            graph[i].clear();
            dist.clear();
        }
        for(int i = 0;i<n;i++)
            dist.push_back(new Treap(0));

        for(int i = 0;i<n-1;i++){
            cin>>u>>v;
            u--,v--;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        // cout<<"HI"<<endl;
        // for(auto c:graph[24844])cout<<c<<" ";
        // cout<<"HI"<<endl;;
        // cout<<endl;
        mn = (n-1)-r;
        mx = (n-1)-l;
        z[0] = 0;
        z[1] = 0;
        dfs(0);
        cout<<z[0]-z[1]<<endl;
    }
    return 0;
}
