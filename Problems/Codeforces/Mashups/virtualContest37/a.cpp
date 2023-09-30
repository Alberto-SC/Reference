#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

vector<int> padre;
vector<int> sz;
int raiz(int v){
    return v== padre[v]?v:padre[v] = raiz(padre[v]);
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
bool same(int u,int v){
    return (raiz(u) == raiz(v));
}

signed main(){__
	int t= 1,n;
    while(t--){
        cin>>n;
        vector<pair<int,int>> nums(n);
        padre.resize(n);
        sz.resize(n,1);
        iota(padre.begin(),padre.end(),0);
        
        for(auto &[x,y]:nums)cin>>x>>y;
        for(int i = 0;i<n;i++){
            for(int j = i+1;j<n;j++){
                if(nums[i].first == nums[j].first || nums[i].second ==nums[j].second){
                    union_bySize(i,j);
                }
            }
        }
        set<int> st;
        for(int i = 0;i<n;i++)
            st.insert(raiz(i));
        cout<<st.size()-1<<endl;
    }
    return 0;
}  
