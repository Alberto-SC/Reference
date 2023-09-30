#define _GLIBCXX_DEBUG 1
#define _GLIBCXX_DEBUG_PEDANTIC 1
#define _FORTIFY_SOURCE 2
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define x first 
#define y second
int B;
vector<pair<lli,pair<lli,lli>>> graph[10007];
const lli INF = 10e3;
const int MAX = 1440007;
lli D[MAX];
lli P[MAX];
lli N;

int maxn = 100*100+7;
void dijkstra(lli s){
    for(int i=0;i<maxn;i++)D[i] = INF;
    D[s] = 0;
    priority_queue<pair<pair<lli,lli>,lli>,vector<pair<pair<lli,lli>,lli>>,greater<pair<pair<lli,lli>,lli>>> q;
    q.push({{0,0},s});
    while(!q.empty()){
        pair<pair<lli,lli>,lli> p = q.top();
        q.pop();
        int u = p.y;
        lli dist = p.x.x;
        lli dist2 = p.x.y;
        if(dist > D[u]) continue;
        for(auto pr: graph[u]){
            int v = pr.x;
            lli next_dist = dist + pr.y.x;
            lli n_dist = dist2+pr.y.y;
            if(n_dist>B)continue;
            if(next_dist < D[v]){    
                D[v] = next_dist;
                P[v] = u;
                q.push({{next_dist,n_dist},v});
            }
            // q.push({{next_d     ist,n_dist},v});

        }   
    }
}


void add_edge(int u,int v,int w,int d){
    cout<<"EDGE "<<u<<" "<<v<<" "<<w<<endl;
    graph[u].push_back({v,{w,d}});
    graph[v].push_back({u,{w,d}});
}
int dist(int x,int y,int x2,int y2){
    double z = (x-x2)*(x-x2);
    double zw = (y-y2)*(y-y2);
    return (int)ceil(sqrt(z+zw));
}
int main(){
    lli t = 1,e,n,x,y,s,c0,l,x1,y1,x0,y0;
    auto f= [&](int x,int y){
        return (y*10)+x;
    };

    cin>>x0>>y0;
    x0--,y0--;
    s = f(x0,y0);
    cin>>x1>>y1;
    x1--,y1--;
    e = f(x1,y1);
    cin>>B;
    cin>>c0;
    cin>>t;
    vector<lli> cost(t+1);
    cost[0] = c0;
    for(lli i = 1;i<=t;i++)
        cin>>cost[i];
    cin>>n;
    vector<lli> D1;
    vector<lli> edges[n];
    vector<pair<int,int>> coords;
    for(int i = 0;i<n;i++){
        cin>>x>>y;
        x--,y--;
        cin>>l;
        coords.push_back({x,y});
        D1.push_back(f(x,y));
        for(int j = 0;j<l;j++){
            cin>>x>>y;
            edges[i].push_back(x);
            edges[i].push_back(y);
        }
    
    }
    cout<<"HI"<<endl;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<edges[i].size();j+=2){
            add_edge(D1[i],D1[edges[i][j]],dist(coords[i].x,coords[i].y,coords[edges[i][j]].x, coords[edges[i][j]].y)*cost[edges[i][j+1]],dist(coords[i].x,coords[i].y,coords[edges[i][j]].x, coords[edges[i][j]].y));
        }
    }
    cout<<cost[0]<<endl;
    for(int i = 0;i<n;i++){
        cout<<D1[i]<<" "<<dist(x0,y0,coords[i].x,coords[i].y)<<endl;
        cout<<x0<<" "<<y0<<" "<<coords[i].x<<" "<<coords[i].y<<endl;
        add_edge(s,D1[i],dist(x0,y0,coords[i].x,coords[i].y)*cost[0],dist(x0,y0,coords[i].x,coords[i].y));
        add_edge(e,D1[i],dist(x1,y1,coords[i].x,coords[i].y)*cost[0],dist(x0,y0,coords[i].x,coords[i].y));
    }
    cout<<endl;
    cout<<"HI"<<endl;
    dijkstra(s);
    cout<<endl;
    cout<<s<<" "<<e<<endl;
    for(int i = 0;i<60;i++)
        cout<<D[i]<<" ";
    cout<<endl;
    cout<<D[e]<<endl;
    return 0;
}

