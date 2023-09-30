#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
typedef long double ld;
vector<int> vis;
vector<bool> vis2;
bool flag = false;
int N;
const int maxn = 200;
vector<int> graph[maxn];
void dfs(int u){
    int c = 0;
    vis[u] = 1;
    vis2[u] = true;
    for(auto v:graph[u]){
        if(vis2[v])continue;
        dfs(v);
        c++;
    }
    if(c==0){
        int s = accumulate(vis.begin(),vis.end(),0);
        if(s ==N)
            flag =true; 
    }
    vis[u]= 0;

}
vector<int> ans;
void dfs2(int u){
    vis2[u] = true;
    ans.push_back(u);
    for(auto v:graph[u]){
        if(vis2[v])continue;
        dfs2(v);
    }
}
signed main(){__
	int t= 1,n;
    while(t--){
        cin>>n;
        N = n;
        vector<pair<string,ld>> forms(n);
        for(int i = 0;i<n;i++){
            cin>>forms[i].first>>forms[i].second;
        }
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                if(j == i)continue;
                if(forms[i].first=="cube" && forms[j].first=="cube"){
                    if(isgreaterequal(forms[i].second,forms[j].second)){
                        graph[i].push_back(j);
                    }
                }
                if(forms[i].first=="cube" && forms[j].first=="cylinder"){
                    if(isgreaterequal(forms[i].second,2*forms[j].second)){
                        graph[i].push_back(j);
                    }
                }
                if(forms[i].first=="cylinder" && forms[j].first=="cube"){
                    ld d = 2*forms[i].second;
                    d*=d;
                    d/=2.0;
                    ld maxs = sqrt(d);
                    if(i ==2 && j == 0){
                        cout<<maxs<<endl;
                    }
                    if(isgreaterequal(maxs,forms[j].second))
                        graph[i].push_back(j);
                }
                if(forms[i].first=="cylinder" && forms[j].first=="cylinder"){
                    if(isgreaterequal(forms[i].second,forms[j].second))
                        graph[i].push_back(j);
                }
            }
        }
        for(int i = 0;i<n;i++){
            cout<<i<<"-> ";
            for(auto c:graph[i])cout<<c<<" ";
            cout<<endl;
        }
        for(int i = 0;i<n;i++){
            vis.assign(n,0);
            vis2.assign(n,false);
            dfs(i);
            if(flag){
                vis2.assign(n,false);
                dfs2(i);
                break;
            }
        }
        if(!flag)return cout<<"impossible"<<endl,0;
        for(auto c:ans)cout<<c<<" ";
        cout<<endl;
    }
    return 0;
}  
