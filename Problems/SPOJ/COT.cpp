#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
const int maxn =100007;
vector<int> graph[maxn];
int parent[25][maxn];
vector<int> times(maxn);
vector<int> depth(maxn);
vector<int> w(maxn);
int t = 1;
vector<int> versions;

int L[20*maxn],R[20*maxn],st[20*maxn],N;

int newLeaf(int val){
    int p = ++N;
    L[p] = R[p] = 0;
    st[p] = val;
    return p;
}

int newParent(int l,int r){
    int p = ++N;
    L[p] = l;
    R[p] = r;
    st[p] = st[l] +st[r];
    return p;
}
int n;
int build(vector<int> &A,int l = 0,int r = n-1){
    if(l == r)return newLeaf(A[l]);
    int mid = (l+r)>>1;
    return newParent(build(A,l,mid),build(A,mid+1,r));
}

int update(int pos ,int x ,int p,int l = 0,int r = n-1){
    if(l == r)return newLeaf(st[p]+x);
    int mid = (l+r)>>1;
    if(pos<=mid)
        return newParent(update(pos,x,L[p],l,mid),R[p]);
    else 
        return newParent(L[p],update(pos,x,R[p],mid+1,r));
}

int query(int p1,int p2 ,int p3,int p4,int k,int l = 0,int r = n-1){
    if(l == r)return l;
    int cont = 0;
    int mid = (l+r)>>1;
    if(p3 == p4 && p3 == versions[0]){
        cont = st[L[p2]]-st[L[p1]];
        if(cont>=k)
            return query(L[p1],L[p2],p3,p4,k,l,mid);   
        else 
            return query(R[p1],R[p2],p3,p4,k-cont,mid+1,r);
    }
    else {
        cont = st[L[p1]]-st[L[p3]];
        cont += st[L[p2]]-st[L[p4]];
        if(cont>=k)
            return query(L[p1],L[p2],L[p3],L[p4],k,l,mid);
        else
            return query(R[p1],R[p2],R[p3],R[p4],k-cont,mid+1,r);
    }
}

void dfs(int u,int p = -1,int d = 0){
    parent[0][u] = p;
    times[u] = t++;
    depth[u]= d;
    if(p == -1)
        versions.push_back(update(w[u],1,versions[0]));       
    else 
        versions.push_back(update(w[u],1,versions[times[p]]));
    
    
    for(auto v:graph[u]){
        if(v == p)continue;
        dfs(v,u,d+1);
    }
}

void init(){
    for(int i = 0;i<=n;i++)for(int j = 0;j<25;j++)parent[j][i] = -1;
    dfs(1);
    for(int i = 1;i<25;i++)
        for(int v = 1;v<=n;v++)
            if(parent[i-1][v] != -1)
                parent[i][v] = parent[i-1][parent[i-1][v]];
}

int LCA(int u,int v){
    if(depth[v]<depth[u])swap(u,v);
    int diff = depth[v]-depth[u];
    for(int i = 24;i>=0;i--){
        if((diff>>i)&1){
            v = parent[i][v];
        }
    }
    if(v == u)return u;
    for(int i = 24;i>=0;i--){
        if(parent[i][v]!= parent[i][u]){
            u = parent[i][u];
            v = parent[i][v];
        }
    }
    return parent[0][v];
}


int main(){__
    int u,v,k,m;
    cin>>n>>m;
    vector<int> copy(n);
    vector<int> uniques;
    for(int i = 1;i<=n;i++){
        cin>>w[i];
        copy[i-1] =w[i];
    }
    sort(copy.begin(),copy.end());
    int last = copy[0];
    uniques.push_back(last);
    for(int i = 1;i<n;i++){
        if(copy[i]!= last){
            last = copy[i];
            uniques.push_back(last);
        }
    }
    for(int i = 1;i<=n ;i++)
        w[i] = lower_bound(uniques.begin(),uniques.end(),w[i])-uniques.begin();
    
    for(int i = 0;i<n-1;i++){
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    vector<int> A(n,0);
    versions.push_back(build(A));
    init();
    for(int i = 0;i<m;i++){
        cin>>u>>v>>k;
        int lca = LCA(u,v);
        if(depth[v]<depth[u])swap(u,v);
        int parentlca = parent[0][lca];
        if(parentlca == -1)parentlca = 0;
        if(lca== u){
            int p= parent[0][u];
            if(p == -1)p = 0;
            cout<<uniques[query(versions[times[p]],versions[times[v]],versions[0],versions[0],k)]<<endl;
        }
        else {
            cout<<uniques[query(versions[times[u]],versions[times[v]],versions[times[lca]],versions[times[parentlca]],k)]<<endl;
        }

    }
    return 0;
}