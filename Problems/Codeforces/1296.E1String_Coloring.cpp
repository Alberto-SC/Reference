#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define endl '\n'
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);

bool bipartite = true;
const int maxn = 100007;
vector<int> graph[maxn];
vector<int> color(maxn,-1);
void dfs(int u,int p = -1){
    if(p==-1)
        color[u] = 0;
    else color[u] = color[p]^1;
    for(auto v:graph[u]){
        if(color[v]==-1)dfs(v,u);
        else if(color[v]==color[u])bipartite = false;
    }
}

signed main(){__
    int n;
    cin>>n;
    string s,t;
    cin>>s;
    sort(t.begin(),t.end());
    for(int i = 0;i<n;i++){
        if(s[i]==t[i])continue;
        if(s[i]<t[i]){
            for(int j = i-1;j>=0;j--){
                graph[i].push_back(j);
                if(s[i]==t[j])break;
            }
        }
        else{
            for(int j = i+1;j<n;j++){
                graph[i].push_back(j);
                if(s[i]==t[j])break;
            }
        }
    }
    bool flag= true;
    for(int i = 0;i<n;i++){
        if(color[i]==-1){
            bipartite = true;
            dfs(0);
            flag&=bipartite;
        }
    }
    if(flag){
        cout<<"YES"<<endl;
        for(int i = 0;i<n;i++)
            cout<<color[i];
        cout<<endl;
    }
    else
        cout<<"NO"<<endl;
    

}