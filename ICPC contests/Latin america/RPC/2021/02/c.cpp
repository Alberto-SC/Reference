#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ld long double
const ld eps = 1e-9;
vector<vector<ld>> M;
int getPivotCol(int ncols,vector<ld> row0){
    for(int i=0; i<ncols-1; i++)
        if (row0[i] > 0.0)
        return i;
    return -1;
}

void print(){
    for(auto c:M){
        for(auto d:c)cout<<d<<" ";
        cout<<endl;
    }
}

ld simplex(int nrows, int ncols){
    int pcol, prow;
    while((pcol = getPivotCol(ncols, M[0])) != -1) {
        prow = -1;
        ld minval;
        for(int i=1; i<nrows; i++) {
            if (M[i][pcol] <= 0.0)
                continue;
            if (prow == -1 || M[i][ncols-1]/M[i][pcol] < minval) {
                prow = i;
                minval = M[i][ncols-1]/M[i][pcol];
            }
        }
        assert(prow != -1);
        for(int i=0; i<nrows; i++) {
            if (i == prow) {
                ld factor = M[prow][pcol];
                for(int j=0; j<ncols; j++)
                    M[i][j] /= factor;
            }
            else {
                ld factor = M[i][pcol]/M[prow][pcol];
                for(int j=0; j<ncols; j++) {
                    M[i][j] -= M[prow][j]*factor;
                    if (fabs(M[i][j]) < eps)
                        M[i][j] = 0.0;
                }
            }
        }
    }
    return M[0][ncols-1];
}




signed main(){
    int n, m;
    cout << setprecision(2);
    cout << fixed;
    cin >> n >> m;
    M.resize(n+1,vector<ld>(n+m+1));
    for(int i=0; i<n+1; i++)
        for(int j=0; j<n+m+1; j++)
            M[i][j] = 0.0;
    for(int i=1; i<=n; i++)
        cin >> M[i][n+m];
    for(int j=0; j<m; j++) {
        for(int i=1; i<=n; i++) {
            cin >> M[i][j];
			M[i][j] /= 100.0;
        }
        cin >> M[0][j];
    }
    for(int j=m; j<n+m; j++)
        M[j-m+1][j] = 1.0;
    
    // print();
    ld max = simplex(n+1, n+m+1);
    cout<<-max<<endl;
}
