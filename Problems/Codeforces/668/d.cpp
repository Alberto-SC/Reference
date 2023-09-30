  #include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
const int maxn = 100007;
vector<int> graph[maxn];
vector<int> dis(maxn);

int N;
pair<int,int> BFS(int s){
	queue<int> q;
	q.push(s); 
  dis.assign(N,-1);
	dis[s] = 0;
	while(!q.empty() ){
		int u = q.front();
		q.pop();
		for(int v : graph[u]){
			if(dis[v] == -1) {
				dis[v] = dis[u]+1;
				 q.push(v);
			}
		}		
	}

	int maxd= 0,in;
  for(int i = 0;i<N;i++){
    if(dis[i]>maxd){
      maxd = dis[i];
      in = i;
    }
  }
	return make_pair(in,maxd);
}

int main(){__
    int t = 1,n,a,b,da,db,u,v;
    cin>>t;
    while(t--){
        cin>>n>>a>>b>>da>>db;
        N =n;
        for(int i = 0;i<n;i++)graph[i].clear();
        for(int i = 0;i<n-1;i++){
          cin>>u>>v;
          graph[--u].push_back(--v);
          graph[v].push_back(u);
        }
        int dim = BFS(BFS(0).first).second;
        BFS(--a);
        int dist= dis[--b];
        if(dist<=da)cout<<"Alice"<<endl;
        else if(min(db,dim)>2*da)cout<<"Bob"<<endl;
        else cout<<"Alice"<<endl;
    }
    return 0;
}

