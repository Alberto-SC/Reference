#include <bits/stdc++.h>
using namespace std;
vector<int> s;
vector<int> a;
typedef long long int lli;
const int maxn = 100007;
vector<int> graph[maxn];
int last =0 ;


void dfs(int u, int d = 1, int f = 0) {
	if(d%2==0){
		if(graph[u].size()>0) {
			a[u] = 2e9;
			for (auto v : graph[u]){
				a[u] = min(a[u], s[v] - s[f]);
            }

			if (a[u] < 0){
                cout<<-1<<endl;
				exit(0);
			}
		}
        else a[u] = 0;
		s[u] = s[f] + a[u];
	}
    else{
        if(u!= 0)
	        a[u] = s[u] - s[f];
    }

	for(auto v: graph[u])
		dfs(v, d + 1, u);
}
int main(){
    int n,p;
    cin>>n;
    for(int i = 1;i<n;i++){
        cin>>p;
        p--;
        graph[p].push_back(i);
    }
    s.resize(n);
    a.resize(n);
    for(auto &c:s)cin>>c;
    a[0]= s[0];
    lli ans = 0;
    dfs(0);
    for(int i = 0;i<n;i++)ans+=a[i];
    cout<<ans<<endl;
    return 0;
}