#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

vector<string> M;

vector<int> fx = {+1,-1,+0,+0};
vector<int> fy = {+0,+0,-1,+1};
int n,m;
bool valid(int x,int y){
    if(x<0 ||y<0)return false;
    if(x>=n || y>=m)return false;

    for(int i = 0;i<4;i++){
        int nx = x+fx[i];
        int ny = y+fy[i];
        if(nx<0 ||ny<0)continue;
        if(nx>=n|| ny>=m)continue;
        if(M[nx][ny]=='#')return false;
    }
    return true;
}
const int INF = 1e9;
signed main(){__
    int T;
    cin>>T;
    while(T--){
        cin>>n>>m;
        M.resize(n);
        for(int i = 0;i<n;i++)
            cin>>M[i];
        vector<vector<int>> dis(n,vector<int> (m,INF));
        vector<vector<int>> vis(n,vector<int> (m,0));
        vector<vector<pair<int,int>>> parent(n,vector<pair<int,int>> (m,{-1,-1}));

        deque<pair<int,int>> q; 
        for(int i = 0;i<n;i++){
            if(valid(i,m-1)){
                dis[i][m-1] = M[i][m-1]=='.';
                if(dis[i][m-1])
                    q.push_front({i,m-1});
                else 
                    q.push_back({i,m-1});
            }
        } 

        while(q.size()){
            auto p = q.front();
            q.pop_front();
            int x = p.first;
            int y = p.second;
            for(int i = x-1;i<=x+1;i+=2){
                for(int j = y-1;j<=y+1;j+=2){
                    if(valid(i,j)){
                        if(dis[i][j]>dis[x][y]+(M[i][j]=='.')){
                            int w = dis[x][y]+(M[i][j]=='.');
                            dis[i][j] = w;
                            parent[i][j] = {x,y};
                            if(w)
                                q.push_back({i,j});
                            else 
                                q.push_front({i,j});
                        }
                    }
                }
            }
        }

        int mn = INF,x,y;
        for(int i = 0;i<n;i++){
            if(dis[i][0]<mn){
                mn = min(mn,dis[i][0]);
                x = i;
                y = 0;
            }
        }
        if(mn ==INF){
            cout<<"NO"<<endl;
            continue;
        }
        while(y!=-1){
            M[x][y] = '#';
            tie(x,y) = parent[x][y];
        }
        cout<<"YES"<<endl;
        for(int i = 0;i<n;i++){
            cout<<M[i]<<endl;
        }
    }


    return 0;
}