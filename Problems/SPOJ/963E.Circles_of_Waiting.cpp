#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define INF INT_MAX
const double EPS = 1e-9;
typedef long long int lli;
typedef long double ld;
struct F{
    lli n,d;
    F(lli n, lli d):n(n),d(d){}

    F operator *(const F b){
        return F(n*b.n,d*b.d);
    }
    F operator /(const F b){
        return F(n*b.d,d*b.n);
    }
    F operator -(const F b){
        return F((b.d*n)-(d*b.n),d*b.d);
    }
    F operator +(const F b){
        return F((b.d*n)+(d*b.n),d*b.d);
    }
    F operator -=(const F b){
        (*this) = (*this)-b;
    }
    F operator +=(const F b){
        (*this) = (*this)+b;
    }

};
template <typename T>
struct Matrix {
    vector < vector <T> > A;
    int r,c;
    Matrix(){
        this->r = 0;
        this->c = 0;
    }
    Matrix(int r,int c){
        this->r = r;
        this->c = c;
        A.assign(r , vector <T> (c));
    }

    Matrix(int r,int c,const T &val){
        this->r = r;
        this->c = c;
        A.assign(r , vector <T> (c , val));
    }
    Matrix(int n){
        this->r = this->c = n;
        A.assign(n , vector <T> (n));
        for(int i=0;i<n;i++)
            A[i][i] = (T)1;
    }
   
    vector<T>& operator [] (int i){
        assert(i < r);
        assert(i >= 0);
        return A[i];
    }

    const vector<T>& operator [] (int i) const{
        assert(i < r);
        assert(i >= 0);
        return A[i];
    }

    friend ostream& operator << (ostream &out,const Matrix<T> &M){
        for (int i = 0; i < M.r; ++i) {
            for (int j = 0; j < M.c; ++j) {
                out << M[i][j] << " ";
            }
            out << '\n';
        }
        return out;
    }
    int gauss (vector<F> & ans) {
        Matrix<ld> Temp(this->r,this->c);
        int n = this->r;
        int m = this->c-1;
        for(int i = 0;i<n;i++)
            for(int j = 0;j<=m;j++)
                Temp[i][j] = (ld)A[i][j];
        vector<int> where (m, -1);
        for (int col=0, row=0; col<m && row<n; ++col) {
            int sel = row;
            for (int i=row; i<n; ++i)
                if (fabs (Temp[i][col]) > fabs (Temp[sel][col]))
                    sel = i;
            if (fabs (Temp[sel][col]) < EPS)
                continue;
            swap(Temp[sel],Temp[row]);
            where[col] = row;

            for (int i=0; i<n; ++i)
                if (i != row) {
                    ld c = Temp[i][col] / Temp[row][col];
                    for (int j=col; j<=m; ++j)
                        Temp[i][j] -= Temp[row][j] * c;
                }
            row++;
        }
        ans.assign (m, 0);
        for (int i=0; i<m; ++i)
            if (where[i] != -1)
                ans[i] = Temp[where[i]][m] / Temp[where[i]][i];
        for (int i=0; i<n; ++i) {
            ld sum = 0;
            for (int j=0; j<m; ++j)
                sum += ans[j] * Temp[i][j];
            if (fabs (sum - Temp[i][m]) > EPS)
                return 0;
        }

        for (int i=0; i<m; ++i)
            if (where[i] == -1)
                return INF;
        return 1;
    }


};

vector<int> fx = {1,-1, 0,0};
vector<int> fy = {0, 0,-1,1};
int main(){
    int R,a1,a2,a3,a4;
    cout<<fixed<<setprecision(5);
    cin>>R>>a1>>a2>>a3>>a4;
    vector<vector<F> a;
    auto valid = [&](int x,int j){
        if(x<0 || y <0)return false;
        if(x>2*R || y>2*R)return false;
        return true;
    };
    auto f = [&](int x,int y){
        return (x*2*R)+y;
    };
    vector<vector<F>> M(2*R,vector<F> (2*R));
    for(int i= 0;i<=R*2;i++){
        for(int j = 0;j<=R*2;j++){
            for(int k = 0;k<4;k++){
                int nx = i+fx[k];
                int ny = j+fy[k];
                if(valid(nx,ny)){
                    M[f(i,j)][f(nx,ny)];                
                }
            }
        }
    }
    ac[v]+=c;
    }
    if(s == e){
        ld ans = 0;
        cout<<ans<<endl;
        continue;
    }
    Matrix<ld> SLAE(n-1,n);
    for(int i = 0;i<n;i++){
        if(i == e)continue;
        for(int j = 0;j<n;j++){
            if(j == e)continue;
            if(i == j)SLAE[i-(i>e?1:0)][j-(j>e?1:0)] = 1;
            else 
                SLAE[i-(i>e?1:0)][j-(j>e?1:0)] = -(graph[i][j]*1.0)/ac[i];                 
        }
    }
    vector<ld> ans(n-1);
    for(int i = 0;i<n-1;i++)
        SLAE[i][n-1] =1;
    SLAE.gauss(ans);
    cout<<ans[s-(s>e?1:0)]<<endl;
    return 0;
}