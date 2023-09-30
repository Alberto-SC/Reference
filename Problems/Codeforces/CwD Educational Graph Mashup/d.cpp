#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

const int maxn = 10007;
vector<int> sz(maxn);
vector<int> c(maxn);
vector<int> graph[maxn];
bool flag = true;
vector<int> res[maxn];

void unir(vector<int> &A,vector<int> &B){
    for(auto c:B){
        A.push_back(c);
    }
}

void dfs(int u,int p = -1){
    sz[u] = 1;
    for(auto v:graph[u]){
        if(v== p)continue;
        dfs(v,u);
        if(!flag)return;
        sz[u]+=sz[v];
        unir(res[u],res[v]);
    }
    if(c[u]>= sz[u]){flag = false;return;}
    res[u].insert(res[u].begin()+c[u],u);    
}

int main(){
	int t= 1,n,p;
    cin>>n;
    int root;
    for(int i = 0;i<n;i++){
        cin>>p>>c[i];
        if(p!= 0){
            p--;
            graph[i].push_back(p);
            graph[p].push_back(i);
        }
        else    
            root = i;
    }

    dfs(root);
    if(!flag)cout<<"NO"<<endl;
    else {
        cout<<"YES"<<endl;
        vector<int> ans(n);
        for(int i = 0;i<n;i++)
            ans[res[root][i]] = i+1;
        for(auto c:ans)cout<<c<<" ";
        cout<<endl;
    }
    return 0;
}

