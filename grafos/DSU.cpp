#include <bits/stdc++.h>
using namespace std; 
vector<int> padre;
vector<int> sz;
int raiz(int v) {
    if (v == padre[v])
        return v;
    return padre[v] = raiz(padre[v]);
}
void union_bySize(int u,int v){
    u = raiz(u);
    v = raiz(v);
    if (u != v) {
        if (sz[u] < sz[v])
            swap(u, v);
        padre[v] = u;
        sz[u] += sz[v];
    }  
}
int main(){
    return 0;
}