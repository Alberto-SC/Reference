#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
const lli maxn =200007;
vector<lli> graph[maxn];
vector<lli> val(maxn);
vector<lli> ans;
vector<bool> used(maxn);

void add_edge(lli u,lli v){
    graph[u].push_back(v);
}
lli res;
void dfs(lli u){
    for(auto v:graph[u])
        dfs(v);
    
    for(auto v:graph[u]){
        if(val[v]>0){
            val[u]+= val[v];
            ans.push_back(v);
            used[v] = true;
        }
    }
}
   

void dfs2(lli u ){
    if(!used[u])ans.push_back(u);
    for(auto v:graph[u])
        dfs2(v);  

}

int main(){
    lli n;
    cin>>n;
    for(lli i = 0;i<n;i++)
        cin>>val[i];
    vector<lli> b(n);
    for(auto &c:b)cin>>c;
    for(lli i = 0;i<n;i++){
        if(b[i]!= -1){
            add_edge(b[i]-1,i);
        }
    }
    for(lli i = 0;i<n;i++){
        if(b[i]== -1)
            dfs(i);
    }
    for(int i = 0;i<n;i++)
        if(b[i] == -1)
            dfs2(i);
    for(int i = 0;i<n;i++)res+=val[i];
    cout<<endl;
    cout<<res<<endl;
    for(auto c:ans)cout<<c+1<<" ";
    cout<<endl;
    return 0;
}