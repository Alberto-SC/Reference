#include <bits/stdc++.h>
using namespace std;
const int maxn = 200007;
const int INF  =1000000007;
#define print(A) for(auto c:A)cout<<c<<" ";cout<<endl;
#define printM(A) for(auto c:A){print(c);}
#define endl '\n'
typedef long long int lli;
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' ');\
stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end));\
i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define cerr(s) cerr << "\033[48;5;196m\033[38;5;15m" << s << "\033[0m"
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << endl;
	err(++it, args...);
}
vector<pair<int,int>> graph[maxn];
void add_edge(int u ,int v,int c){
    graph[u].push_back({v,c});
    graph[v].push_back({u,c});
}
vector<bool> used(maxn);
set<pair<int,int> > s;
int d[maxn];
int k[maxn];
map<int,int>  mp;
int n;
void dijkstra(int source){
    for(int i = 0; i < n; ++i){
        k[i] = 0;
		d[i] = INF;
    }

	d[source] = 0;
	s.insert(make_pair(d[source], source));
    while (!s.empty()) {
        int v = s.begin()->second;
        s.erase(s.begin());
        for(auto c:graph[v]){
            int u = c.first;
            int w = c.second;
            if (d[v] + w < d[u]) {
                s.erase(make_pair(d[u], u));
                d[u] = d[v]+  w;
                k[u] = v;
                s.insert(make_pair(d[u], u));
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int m,a,b,c,u,v,t;
    cin>>t;
    while(t--){
        cin>>n>>m>>a>>b>>c;
        vector<int> p(m);
        vector<lli> sum(m+1);
        for(int i = 0;i<n;i++)graph[i].clear();
        for(auto &c:p)cin>>c;
        sort(p.begin(),p.end());
        sum[m] = 0;
		for (int i =m-1;i>=0;i--)sum[i]=sum[i+1]+p[i];
        for(int i = 0;i<m;i++){
            cin>>u>>v;
            u--;
            v--;
            add_edge(u,v,1);
        }
        vector<int> D[3];
        dijkstra(--a);
        D[0] = vector<int>(d,d+n);
        dijkstra(--b);
        D[1] = vector<int>(d,d+n);
        dijkstra(--c);
        D[2] = vector<int>(d,d+n);
        lli ans = 1000000000000000;
        // print(sum)
        for (int i = 0; i < n; i++) {
			int one = D[0][i] + D[2][i];
			int two = D[1][i];
			if (one + two > m) continue;
			lli cur = (sum[0] - sum[two]) * 2 + (sum[two] - sum[two + one]);
            // error(one,two)
            // cout<<i<<" "<<cur<<endl;
			ans = min (ans, cur);
		}
        cout<<ans<<endl;
    }
    return 0;
}