#include <bits/stdc++.h>
using namespace std; 
vector<int> h;
vector<int> padre;
vector<int> sz;
#define print(A)for(auto c:A)cout<<c<<" ";cout<<endl;
int raiz(int v) {
    if (v == padre[v])
        return v;
    return padre[v] = raiz(padre[v]);
}
void union_find(int u,int v){
    u = raiz(u);
    v = raiz(v);
    if (u != v) {
        if (sz[u] < sz[v])
            swap(u, v);
        padre[v] = u;
        sz[u] += sz[v];
    }  
}
map<pair<int,int>,int> mp;

bool comp(pair<pair<int,int>,int> A, pair<pair<int,int>,int> B){
    return A.second<B.second;
}

bool comp2(pair<int,int> A, pair<int,int> B){
    return A.second<B.second;
}
int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);  
    int n,m,q,x,u,v;
    cin>>n>>m>>q;
    h.resize(n+1,1);
    padre.resize(n+1,0);
    sz.resize(n+1,1);
    for(int i = 0;i<=n;i++)padre[i] = i;
    vector<pair<int,int>> nodes(n-1);
    vector<pair<pair<int,int>,int>> nodesc(n-1);
    vector<int> indexes;
    for(int i = 0;i<n-1;i++){
        cin>>u>>v; 
        nodes[i] = {u,v};
        nodesc[i]= {{u,v},m+1+i};
    }
    sort(nodes.begin(),nodes.end());
    sort(nodesc.begin(),nodesc.end());
    for(int i = 0;i<m;i++){
        cin>>u>>v;
        int index = lower_bound(nodes.begin(),nodes.end(),make_pair(u,v))-nodes.begin();
        nodesc[index].second = i+1;
    }
    sort(nodesc.begin(),nodesc.end(),comp);
    vector<pair<pair<int,int>,int>>query(q);
    for(int i = 0;i<q;i++){
        cin>>x>>u;
        query[i] = {{x,u},i};
    }
    sort(query.rbegin(),query.rend()); 
    int j = n-2;
    vector<pair<int,int>> ans;
    for(int i = 0;i<q;i++){
        while(nodesc[j].second> query[i].first.first && j>=0){
            union_find(nodesc[j].first.first, nodesc[j].first.second);
            j--;
        }
        // print(padre)
        ans.push_back(make_pair(sz[raiz(query[i].first.second)],query[i].second));
    }
    sort(ans.begin(),ans.end(),comp2);
    for(auto c:ans)cout<<c.first<<endl;
	return 0;
}