#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
/*
    [Simplex method]
    [Tested in RPC 2021 02 problem C]
*/

vector<vector<int>> M;

void print(){
    for(auto c:M){
        for(auto d:c)cout<<d<<" ";
        cout<<endl;
    }
}

int getPivotCol(int ncols,vector<int> row0){
    for(int i=0; i<ncols-1; i++)
        if (row0[i] > 0.0)
        return i;
    return -1;
}

int dual_simplex(int nrows, int ncols){
    int pcol, prow;
    while((pcol = getPivotCol(ncols, M[0])) != -1) {
        prow = -1;
        int minval;
        for(int i=1; i<nrows; i++) {
            if (M[i][pcol] <= 0)
                continue;
            if (prow == -1 || M[i][ncols-1]/M[i][pcol] < minval) {
                prow = i;
                minval = M[i][ncols-1]/M[i][pcol];
            }
        }
        assert(prow != -1);
        for(int i=0; i<nrows; i++) {
            if (i == prow) {
                int factor = M[prow][pcol];
                for(int j=0; j<ncols; j++)
                    M[i][j] /= factor;
            }
            else {
                int factor = M[i][pcol]/M[prow][pcol];
                for(int j=0; j<ncols; j++) {
                    M[i][j] -= M[prow][j]*factor;
                }
            }
        }
    }
    print();
    return M[0][ncols-1];
}

/* Get maximum for a linear ecuation a1*x1 + a2*x2 + a3*x3 ... ai*xi
        subject to 
                b1*x1 + b2*x2 + b3*x3 + ... + ai*xi<= z1
                c1*x1 + c2*x2 + c3*x3 + ... + ci*xi<= z2
                d1*x1 + d2*x2 + d3*x3 + ... + di*xi<= z3
                        .
                        .
                        .
                y1*x1 + y2*x2 + y3*x3 + ... + yi*xi<= z_i
        
        for given ai , bi, ci, di, zi
        example 
            maximize x1+ 2x2 + 5x2
        subject to 
            2x1 + x2 +x3  <=14
            4x1 +2x2 +3x3 <=28
            2x1 +5x2 +5x3 <=30
        
        x1,x2,x3 >=0

        if you have a restriction like 
            4x1 +2x2 +3x3 >= 28
        only multiply by -1 and you have the correct form
            -4x1 -2x2 -3x3 <= -28
        

    the matrix has the form 
    a1  a2  a3 ... ai  0  0  0  ...  0  0
    b1  b2  b3 ... bi  1  0  0  ...  0  z1
    c1  c2  c3 ... ci  0  1  0  ...  0  z2
    d1  d2  d3 ... di  0  0  1  ...  0  z3
    .
    .
    .
    y1  y2  y3 ... yi  0  0  0  ...  1  zi
    note the identity matrix in middle of the ecuation and the restriction and the first row is the linear equation to maximize 
*/


signed main(){__
	int t= 1,n,m;
    while(t--){
        cin>>n>>m;
        vector<vector<int>> C(n,vector<int>(m));
        vector<int> a(n);
        vector<int> b(m);
        for(auto &c:a)cin>>c;
        for(auto &c:b)cin>>c;
        for(auto &c:C)for(auto &d:c)cin>>d;
        M.resize(2+(n*m),vector<int>((n*m)+2+(n*m)));
        for(int i = 0;i<n*m;i++)
            M[0][i] = C[i/m][i%m];  
        for(int i = 0;i<n*m;i++)
            M[1][i] = -b[i%3];
        for(int i = 2;i<(n*m)+2;i++)
            M[i][i-2] = 1;
        for(int i = 2;i<(n*m)+2;i++)
            M[i].back() = 1;
        for(int i = 0;i<n;i++)
            M[1][(n*m)+1+(n*m)] -=a[i];
        for(int i = 1;i<(n*m)+2;i++)
            M[i][i+(n*m)-1] = 1;



        // M.resize((n*m)+1,vector<int>(2+(n*m)+(n*m)));
        // for(int i = 0;i<n;i++)
        //     M[0][0] -= a[i];
        // for(int i = 1;i<(n*m)+1;i++)
        //     M[0][i] = 1;
        
        // for(int i = 1;i<=n*m;i++)
        //     M[i][0] = -b[(i-1)%3];
        // for(int i = 1;i<=n*m;i++){
        //     M[i][i] = 1;
        //     M[i][i+(n*m)] = 1;
        // }
        // for(int i = 1;i<=n*m;i++){
        //     M[i].back() = C[(i-1)/m][(i-1)%m];
        // }
        print();
        // int mn = simplex((n*m)+1,(n*m)+2+(n*m));
        // cout<<mn<<endl;
    }
    return 0;
}  

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



// a_1x1 +a_2x2 + a_