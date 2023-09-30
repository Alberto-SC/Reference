#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

#define NOT_IN_STACK 0
#define IN_STACK 1
const int maxn = 200007;
vector<int> graph[maxn];

vector<bool> vis(maxn);
int cont;

void dfs(int u){
    if(vis[u])return;
    vis[u] = true;
    cont++;
    for(auto v:graph[u])
        dfs(v);
}

signed main(){__
    int t,n,m,E;
    cin>>t;
    while(t--){
        cin>>n>>m>>E;
        vector<vector<char>> A(n,vector<char> (m));
        vector<vector<char>> B(n,vector<char> (m));
        vector<vector<int>> M(n,vector<int> (m));
        vis.assign(n*m,false);
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                cin>>A[i][j];
            }
        }
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                cin>>B[i][j];
            }
        }
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(A[i][j]!=B[i][j]){
                    M[i][j] = 1;
                }
            }
        }
        auto F= [&](int x,int y){
            return (x*m)+y;
        };
        for(int i = 0;i<n;i++){
            int last = -1;
            for(int j = 0;j<m;j++){
                if(M[i][j]==1 &&last!=-1){
                    graph[F(i,last)].push_back(F(i,j));
                    graph[F(i,j)].push_back(F(i,last));
                    last = j;
                }
                else if(M[i][j]==1) last = j;
            }
        }
        for(int i = 0;i<m;i++){
            int last = -1;
            for(int j = 0;j<n;j++){
                if(M[j][i]==1 &&last!=-1){
                    graph[F(last,i)].push_back(F(j,i));
                    graph[F(j,i)].push_back(F(last,i));
                }
                else if(M[j][i]==1)last = j;
            }
        }
        int ans = 0;
        bool flag = true;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(M[i][j]==0)continue;
                if(!vis[F(i,j)]){
                    cont =0;
                    dfs(F(i,j));
                    if(cont&1)flag = false;
                    else ans +=cont/2;
                }
            }
        }
        if(!flag)cout<<-1<<endl;
        else {
            cout<<ans<<endl;
        }
    }
}