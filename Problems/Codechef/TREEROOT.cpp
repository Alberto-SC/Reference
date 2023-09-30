#include <bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
vector<int> G(50);
vector<bool> used (50);
int n;
bool flag = false;
int solve(int u){
    if(!G[u]){
        bool f = true;
        for(int i = 1;i<=n;i++){
            if(!used[i])f = false;
        }
        if(f)flag = true;
        return 1;
    }
    int ans = 0;
    for(int i = 1;i<= G[u]/2;i++){
        if(i<=n && G[i]-i <=n && i!= G[i]-i && !used[i] && !used[G[u]-i]){
            used[i]  = true;
            used[G[u]-i] = true;
            //cout<<"U ->"<<u<<" "<<i<<" "<<G[u]-i<<endl;
            int S =  solve(i) + solve(G[u]-i);
            ans =max(ans,S);
            used[i] = false;
            used[G[u]-i] = false;
        }
    }
    if(!used[G[u]]){
        used[G[u]] = true;
        ans = max(ans,solve(G[u]));
        used[G[u]] = false;
    }
    return ans;
}

signed main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        int u,x;
        int cont = 0;
        for(int i = 0;i<n;i++){
            cin>>u>>x;
            if(x==0)cont++;
            G[u] = x;
        }
        vector<int> ans;
        cout<<cont<<endl;
        //used[6] = true;
        //cout<<solve( 6)<<endl;
        for(int i = 1;i<=n;i++){
            used[i] = true;
            flag = false;
            int leafs = solve(i);
            used[i] = false;
            if(leafs==cont && flag)ans.push_back(i);
        }
        for(auto c:ans)cout<<c<<" ";
        cout<<endl;
    }
}
