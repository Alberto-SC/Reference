#include <bits/stdc++.h>
using namespace std;
const int maxn = 200007;
vector<int> p(maxn);
vector<int> sz(maxn,1);

int raiz(int u){
    return p[u] ==u?u:p[u] = raiz(p[u]);
}

bool unionBySize(int u,int v){
    u = raiz(u);
    v = raiz(v);
    if(u!= v){
        if(sz[u]<sz[v])swap(u,v);
        sz[u]+=sz[v];
        p[v] = u;
        return false;
    }
    return true;
}

int main(){
    int n;
    cin>>n;
    iota(p.begin(),p.end(),0);
    vector<int> parent(n);
    for(auto &c:parent)cin>>c;
    vector<int> roots;
    vector<int> cycles;
    for(int i = 0;i<n;i++){
        if(i == parent[i]-1)roots.push_back(i);
        else{
            if(unionBySize(i,parent[i]-1))cycles.push_back(i);
        } 
    }
    if(roots.size()==0){
        roots.push_back(cycles[0]);
        parent[cycles[0]] = cycles[0]+1;
        cout<<cycles.size()+roots.size()-1<<endl;
        for(int i = 1;i<cycles.size();i++)
            parent[cycles[i]] = roots[0]+1;

    }
    else {
        cout<<cycles.size()+roots.size()-1<<endl;
        for(auto c:cycles)
            parent[c] = roots[0]+1;

        for(int i = 1;i<roots.size();i++)
            parent[roots[i]] = roots[0]+1;
    }
    for(auto c:parent)cout<<c<<" ";
    cout<<endl;
    return 0;
}