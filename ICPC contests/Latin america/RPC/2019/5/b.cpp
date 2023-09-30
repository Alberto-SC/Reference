#include <bits/stdc++.h>
using namespace std;
int dx[] = {1, -1, 0, 0,1,-1};
int dy[] = {0, 0, 1, -1,1,-1};
vector<vector<int>> matrix;
int dfs(int x, int y, int row, int col) {
	int tam = 1;
    matrix[x][y] = 0;
	for (int i = 0; i < 6; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (matrix[nx][ny] == 1) {
			tam += dfs(nx, ny, row, col); 
		}
	}
	return tam;
}

int main(){
    int h,n,m;
    cin>>h>>m>>n;
    matrix.resize(m + 2, vector<int>(m + n + 2, 0));
    char c;
    for(int i = 1; i <= m; i++) {
        for(int j = 1 + i/2; j <= n + i/2; j++) {
            cin >> c;
            matrix[i][j] = (c == '.');
        }
    }

    vector<int> tams;
    for (int i = 0; i < m + 2; i++) {
        for (int j = 0; j < m+n+2; j++) {
            int tam;
            if (matrix[i][j] == 1) {
                matrix[i][j] = 0;
                tam = dfs(i, j, m+2,n+m+2);
                tams.push_back(tam);
            }
        }
    }
    sort(tams.begin(), tams.end());
    reverse(tams.begin(), tams.end());

    for(int j = 0; j <= (int)tams.size(); j++) {
        if(h <= 0) {
            cout << j << endl;
            break;
        }
        h -= tams[j];
    }
    return 0;
}