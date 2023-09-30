#include <bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
int main (){__
	int n, m; cin>>n>>m;
	vector<vector<char>> grid(n, vector<char>(m, '_'));
	vector<pair<int, int>> ubC (m, {-1, -1});
	vector<vector<int>> cols(m);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			char x; cin>>x;
			grid[i][j] = x;
			if(x == 'C'){
				cols[j].push_back(i);
				if(ubC[j] == make_pair(-1, -1)){
					ubC[j] = {i, j};
				}
			}
		}
	}	
	
	int res = 0;
	for(int it = 0; it < ubC.size(); it++) {
		int x, y;
		x = ubC[it].first;
		y = ubC[it].second;
		
		if(x == -1) continue;
		if(grid[x][y] == '_')continue;
		
		int cont = 0;
		while(y<m){
			int last = cols[y].size()?cols[y].back():x;
			while(cols[y].size() && cols[y].back()>=x){
				grid[cols[y].back()][y] = '_'; 
				cols[y].pop_back();
				cont++;
			}
			cont++;
			x = max(last,x);
			y++;
		}
		res++;
	}
	cout << res << "\n";
	return 0;
}