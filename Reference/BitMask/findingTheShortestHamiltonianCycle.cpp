/**
 * Author: Alberto Silva
 * Description:  Search for the shortest Hamiltonian cycle. 
 *					Let the directed graph G = (V, E) have 
 *					n vertices, and each
 *					edge have weight d(i, j). We want to find a Hamiltonian 
 *					cycle for which the sum of weights of its edges					is minimal.
 * Time:  $O(n^2 \times n^2)$
 */



#define     BIT(n)  (1 << n)
using namespace std;
const int MAXN	=	20,
const int INF		=	1e9+7;

int g[MAXN][MAXN];
int dp[BIT(MAXN)][MAXN];
int main(){
	int n, m, u, v, w,
	int ans = INF;

	cin>>n>>m;
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < n; ++j)
			g[i][j] = INF;
	}
	
	for (int i = 0; i < BIT(n); ++i){
		for (int j = 0; j < n; ++j)
			dp[i][j] = INF;
	}
	
	for (int i = 0; i < m; ++i){
		cin >> u >> v;
		cin >> g[u][v];
	}
	
	dp[1][0] = 0;
	
	for (int msk = 2; msk < BIT(n); ++msk){
		for (int i = 0; i < n; ++i) if (msk & BIT(i)){
			int tmsk = msk ^ BIT(i);
			for (int j = 0; tmsk && j < n; ++j)
				dp[msk][i] = min(dp[msk][i], dp[tmsk][j] + g[j][i]);
		}
	}
	
	for (int i = 1; i < n; ++i)
	    ans = min(ans, dp[BIT(n) - 1][i] + g[i][0]);
	    
	cout << ans << endl;
	return 0;
}
