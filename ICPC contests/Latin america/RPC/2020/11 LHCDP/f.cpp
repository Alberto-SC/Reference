#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define x first
#define y second

int dist(pair<int,int> A ,pair<int,int> B){
    return abs(A.x-B.x)+abs(A.y-B.y);
}

vector<pair<int,int>> graph[51*51];
const lli inf = 10000000000000ll;
set<pair<lli,int> > st;
lli d[100000];
int p[100000];

int main(){__
    int t = 1,n,k;
    cin>>n>>k;
    int grid[n][n];
    vector<pair<int,int>> pos[k+1];
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            cin>>grid[i][j];
            pos[grid[i][j]].push_back({i,j});
        }
    }
    auto f = [&](int a,int b){
        return (a*n)+b;
    };
    pair<int,int> a;
    pair<int,int> b;
    for(int i = 1;i<=k-1;i++){
        if(pos[i].size()== 0)return cout<<-1<<endl,0;
        for(int j = 0;j<pos[i].size();j++){
            for(int z = 0;z<pos[i+1].size();z++){
                a = pos[i][j];
                b = pos[i+1][z];
                graph[f(a.x,a.y)].push_back({f(b.x,b.y),dist(a,b)});
            }
        }

    }

    pair<int,int> s;
    lli ans = inf;
    for(int i = 0;i<pos[1].size();i++){
        int s = f(pos[1][i].x,pos[1][i].y);
        // cout<<s<<endl;
        for(int i = 0; i<n*n; i++)
            d[i] = inf;
        d[s] = 0;
        st.insert(make_pair(d[s], s));
        while (!st.empty()) {
            int v = st.begin()->second;
            st.erase(st.begin());
            for(auto c:graph[v]){
                int u = c.first;
                int w = c.second;
                if (d[v] + w < d[u]) {
                    st.erase(make_pair(d[u], u));
                    d[u] = d[v]+  w;
                    st.insert(make_pair(d[u], u));
                }
            }
        }
        for(int j = 0;j<pos[k].size();j++){
            int fn = f(pos[k][j].x,pos[k][j].y);
            ans = min(ans,d[fn]);
        }
        // for(int i = 0;i<n*n;i++)
            // cout<<d[i]<<" ";
        // cout<<endl;
    }

    cout<<ans<<endl;

    return 0;
}

