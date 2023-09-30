#include <bits/stdc++.h>
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl '\n'

using namespace std;

const int maxn = 200007;
vector<int> nxt(maxn);
vector<int> graph[maxn];
vector<int> color(maxn,-1);
vector<int> c(maxn);

int k;
int start = -1;
int sum = 0;

void dfs(int u,int p = -1){
    if(p == -1)color[u] = 0;
    else color[u] = 1-color[p];
    
    sum+=c[u];

    for(auto v:graph[u]){
        if(p == v)continue;
        if(color[v]==color[u]){
            if(k>=3)
                color[u] = 2;
            start = v;
        }

        if(color[v]==-1)
            dfs(v,u);
    }

    
    if(color[nxt[u]]==-1)
        dfs(nxt[u],u);
}

signed main(){
    int T,n;
    cin>>T;
    while(T--){
        cin>>n>>k;

        for(int i = 0;i<n;i++)color[i] = -1,graph[i].clear();

        vector<int> nums(n);
        vector<int> rev(n,-1);
        for(int i = 0;i<n;i++){
            cin>>nxt[i];
            nxt[i]--;
            rev[nxt[i]] = i;
            graph[i].push_back(nxt[i]);
            graph[nxt[i]].push_back(i);

        }
        for(int i = 0;i<n;i++)cin>>c[i];

        int ans = 0;
        for(int i = 0;i<n;i++){
            if(color[i]==-1){
                sum = 0;
                start = -1;
                dfs(i);
                if(k == 1)ans+=sum;
                else if(k ==2 && start!=-1){
                    int mn = 1e9;
                    int mnIdx = 0;
                    int u = start;

                    vector<int> outIdx;
                    set<int> cicle;
                    do{
                        cicle.insert(u);
                        if(c[u]<mn){
                            mn = c[u];
                            mnIdx = u;
                        }
                        u = nxt[u];
                    }while(u!=start);


                    color[mnIdx] = 1;
                    color[nxt[mnIdx]] = 1;
                    u = nxt[mnIdx];
                    

                    for(auto v:graph[mnIdx]){
                        if(!cicle.count(v))outIdx.push_back(v);
                    }
                    do{
                        for(auto v:graph[u]){
                            if(!cicle.count(v))outIdx.push_back(v);
                        }
                        color[nxt[u]] = 1-color[u];;
                        u = nxt[u];
                    }while(u!=mnIdx);

                    ans+=mn;
                    for(auto out:outIdx){
                        u = out;
                        while(u!=-1){
                            color[u] = 1-color[nxt[u]];
                            u = rev[u];
                        }
                    }
                }

            }
        }
        cout<<ans<<endl;
        for(int i = 0;i<n;i++){
            if(k == 1)cout<<1<<" ";
            else
                cout<<color[i]+1<<" ";
        } 
        cout<<endl;
    }
    return 0;
}

