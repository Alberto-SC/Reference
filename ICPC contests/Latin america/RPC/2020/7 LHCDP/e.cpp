#define y second
const int maxn = 10000;
int top;
int q[maxn];
int D[maxn];
vector<int> graph[maxn];
const int INF = 10000000;
void bfs(int s,int n){
    for(int i = 0;i<n;i++)
        D[i] = INF;
    D[s] = 0;
    q[top++] = s;
    for(int i = 0;i<top;i++){
        int u = q[i];
        for(auto v:graph[u]){
            if(D[v]<=D[u]+1)continue;
            D[v] = D[u]+1;
            q[top++] = v;
        }
    }
}

void show_graph(const bool undirected = true) {
	ofstream os{"graph.dot"};
	os << (undirected ? "graph" : "digraph");
	os << " G {" << endl;
	for(int u = 0; u < maxn; ++u) {
		for (const auto v : graph[u]) {
			if (!undirected || u <= v) {
				os << "\t" << u << (undirected ? " -- " : " -> ") << v << endl;
			}
		}
	}
	os << "}" << endl;
    /* Displays dot using image viewer 
    / This command is for Linux. You can change this command for a different OS or for a different image viewer.*/
	system("dot -Tpng graph.dot -o graph.png && xdg-open graph.png");
}

int main(){
    int n,F,C,t;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> c(n);
        vector<pair<int,int>> IF(n);
        for(auto &x:c)cin>>x;
        int cont = 0;
        for(int i = 0;i<n;i++){
            IF[i].x =cont;
            IF[i].y =cont+c[i];
            cont+=c[i]+1;
        }
        for(int i = 0;i<cont;i++)graph[i].clear();
        int fila = 0;
        for(int i = 0;i<cont;i++){
            if(i+1<=IF[fila].y)
                graph[i].push_back(i+1);
            else if(i+1>IF[fila].y && fila+1<n )
                graph[i].push_back(IF[fila+1].x);
        


            if(i-1>=IF[fila].x)
                graph[i].push_back(i-1);
            else if(i-1<IF[fila].x && fila-1>=0)
                graph[i].push_back(IF[fila-1].y);
            


            if(fila-1>=0  && c[fila-1]>= i-IF[fila].x)
                graph[i].push_back(IF[fila-1].x+(i-IF[fila].x));
            else if(fila-1>= 0 && c[fila-1]<i-IF[fila].x)
                graph[i].push_back(IF[fila-1].y);
        


            if(fila+1<n && c[fila+1]>= i-IF[fila].x)
                graph[i].push_back(IF[fila+1].x+(i-IF[fila].x));
            else if(fila+1<n && c[fila+1]< i-IF[fila].x)
                graph[i].push_back(IF[fila+1].y);
            


            if(i==IF[fila].y)fila++;
        }
        cin>>F>>C;
        int s = IF[F-1].x;
        s+=C;
        cin>>F>>C;
        int d = IF[F-1].x;
        d+=C;
        top = 0;
        bfs(s,cont);
        show_graph();
        cout<<D[d]<<endl;
    }
    return 0;
}