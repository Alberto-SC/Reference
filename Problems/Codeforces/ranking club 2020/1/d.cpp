#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
const lli INF = 10e15;
const int MAX = 1440007;
lli d[MAX], N; // Keeps minimum distance to each node
vector<pair<int,lli>> graph[MAX]; // Adjacency list
 
void add_edge(int u,int  v,lli cost){
    graph[u].push_back({v,cost});
    // graph[v].push_back({u,cost});
}

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);  
    lli m,n,hm;
    cin>>m>>n;
    int source =n*1440,dest = source+1;
    N = dest;
    vector<lli> u(m),v(m),d(m),c(m),w(n),k(n);
    vector<string> h(m);
    for(int i = 0;i<m;i++)
        cin>>u[i]>>v[i]>>d[i]>>c[i]>>h[i];
    for(int i = 0;i<n;i++)
        cin>>w[i]>>k[i];
    vector<bool> used(n,false);
    for(int i = 0;i<m;i++){
        int z = 0;
        u[i]--;
        v[i]--;
        while(h[i][z]!= ':'){z++;}
        int hour = stoi(h[i].substr(0,z));
        int minutes = stoi(h[i].substr(z+1));
        hm = (60*hour)+minutes;
        if(u[i]== n-1 )continue;
        for(int j = 0;j<1439;j++){
            if(j == hm)add_edge((u[i]*1440)+j,(v[i]*1440)+((hm+d[i]+w[v[i]])%1440),c[i]);
            if(!used[u[i]]){
                    if(j == 479 && u[i]>0)
                        add_edge((u[i]*1440)+479,(u[i]*1440)+480,k[u[i]]);
                    else{
                        add_edge((u[i]*1440)+j,(u[i]*1440)+j+1,0);
                    }
            }
        }
        if(hm == 1439)
                add_edge((u[i]*1440)+1439,(v[i]*1440)+((hm+d[i]+w[v[i]])%1440),c[i]);
        else 
            add_edge(u[i]*1440+1439,u[i]*1440,0);
        used[u[i]]= true;
    }
    
    int last =(n-1)*1440;
    for(int i = 0;i<1440;i++){
        add_edge(source,i,0);
        add_edge(last+i,dest,0);
    }
    set<pair<lli,int> > s;
    for(int i = 0; i < dest+1; i++)
		d[1] = INF;
	d[source] = 0;
	s.insert(make_pair(d[source], source));
        while (!s.empty()) {
        int v = s.begin()->second;
        s.erase(s.begin());
        // cout<<graph[v].size()<<endl;
        for(auto c:graph[v]){
            int u = c.first;
            int w = c.second;
            if (d[v] + w < d[u]) {
                s.erase(make_pair(d[u], u));
                d[u] = d[v]+  w;
                s.insert(make_pair(d[u], u));
            }
        }
    }
    // if(d[dest] == INF)return cout<<-1<<endl,0;
    // cout<<d[dest]<<endl;
    for(auto c:d)cout<<c<<" ";
    cout<<endl;
    return 0;
}
// 3 3
// 1 2 10 10 10:10
// 1 2 10 10 20:20
// 1 2 10 10 8:20
// 100 100
// 100 100
// 100 100