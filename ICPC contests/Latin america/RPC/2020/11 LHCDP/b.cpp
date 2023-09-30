#include <bits/stdc++.h>

using namespace std;

int n,k;
vector<string> m; //map
vector<int> s; //ships
bool vis[5][5];

int dfs(int ship){
	int ans = 0;
	if(ship >= s.size()){
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				if(m[i][j] == 'O' && !vis[i][j])
					return 0;
			}
		}
		return 1;
	}

	for(int i=0; i<n; i++){
		for(int j=0; j<(n-s[ship]+1); j++){
			bool isPos = true;
			for(int k=j; k<j+s[ship]; k++){
				if(vis[i][k] || m[i][k] == 'X'){
					isPos = false;
					break;
				}
			}

			if(isPos){
				for(int k=j; k<j+s[ship]; k++){
					vis[i][k] = true;
				}

				ans += dfs(ship+1);

				for(int k=j; k<j+s[ship]; k++){
					vis[i][k] = false;
				}
			}
		}
	}

	if(s[ship] == 1)
		return ans;
	
	for(int j=0; j<n; j++){
		for(int i=0; i<(n-s[ship]+1); i++){
			bool isPos = true;
			for(int k=i; k<i+s[ship]; k++){
				if(vis[k][j] || m[k][j] == 'X'){
					isPos = false;
					break;
				}
			}

			if(isPos){
				for(int k=i; k<i+s[ship]; k++){
					vis[k][j] = true;
				}

				ans += dfs(ship+1);

				for(int k=i; k<i+s[ship]; k++){
					vis[k][j] = false;
				}
			}
		}
	}

	return  ans;
}

int main(){
	cin >> n >> k;
	m.resize(n);
	s.resize(k);
	for(auto &x:m) cin >> x;
	for(auto &x:s) cin >> x;

	memset(vis, 0, sizeof(vis));

	cout << dfs(0) << endl;

	return 0;
}