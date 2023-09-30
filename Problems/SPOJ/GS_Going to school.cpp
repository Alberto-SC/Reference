#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define INF INT_MAX
const double EPS = 1e-9;
typedef long long int lli;
typedef long double ld;
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
    Matrix operator * (const Matrix<T> &B){    
//     Matrix <T> C(r,B.c,0);
//     for(int i=0 ; i<r ; i++)
//         for(int j=0 ; j<B.c ; j++)
//             for(int k=0 ; k<c ; k++)
//                 C[i][j] = (C[i][j] + ( (long long )A[i][k] * (long long)B[k][j] ));
//     return C;
        Matrix<T> C(r,B.c,0);
        for(int i = 0;i<r;i++){
            for(int j = 0;j<B.c;j++){
                for(int k = 0;k<c;k++){
                    C[i][j] = (C[i][j] + ((lli)A[i][k] * (lli)B[k][j]));
                    if(C[i][j]>= 8ll*mod*mod)
                        C[i][j]%=mod;
                }
            }
        }
        for(int i = 0;i<r;i++)for(int j = 0;j<c;j++)C[i][j]%=mod;
        return C;
    }

    Matrix operator + (const Matrix<T> &B){
        assert(r == B.r);
        assert(c == B.c);
        Matrix <T> C(r,c,0);
        int i,j;
        for(i=0;i<r;i++)
            for(j=0;j<c;j++)
                C[i][j] = ((A[i][j] + B[i][j]));
        return C;
    }
    Matrix operator*(int & c) {
        Matrix<T> C(r, c);
        for(int i = 0; i < r; i++)
            for(int j = 0; j < c; j++)
                C[i][j] = A[i][j] * c;
        return C;
    }
    Matrix operator - (){
        Matrix <T> C(r,c,0);
        int i,j;
        for(i=0;i<r;i++)
            for(j=0;j<c;j++)
                C[i][j] = -A[i][j];
        return C;
    }
    Matrix operator - (const Matrix<T> &B){
        assert(r == B.r);
        assert(c == B.c);
        Matrix <T> C(r,c,0);
        int i,j;
        for(i=0;i<r;i++)
            for(j=0;j<c;j++)
                C[i][j] = A[i][j] - B[i][j];
        return C;
    }
    Matrix operator ^ (long long n){
        assert(r == c);
        int i,j;
        Matrix <T> C(r);
        Matrix <T> X(r,c,0);
        for(i=0;i<r;i++)
            for(j=0;j<c;j++)
                X[i][j] = A[i][j];
        while(n){
            if(n&1)
                C *= X;
            X *= X;
            n /= 2;
        }
        return C;
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


    void operator *= (const Matrix<T> &B){
        (*this) = (*this)*B;
    }

    void operator += (const Matrix<T> &B){
        (*this) = (*this)+B;
    }
   
    void operator -= (const Matrix<T> &B){
        (*this) = (*this)-B;
    }

    void operator ^= (long long n){
        (*this)  =(*this)^n;
    }
    //Inverse
    bool Inverse(Matrix<ld> &inverse){
        if(this->detGauss() == 0)return false;
        int n = A[0].size();
        Matrix<ld> temp(n,2*n);
        for(int i = 0;i<n;i++)
            for(int j = 0;j<n;j++)temp[i][j] =  A[i][j]; 
        Matrix<ld> ident(n);
        for(int i = 0;i<n;i++)
            for(int j = n;j<2*n;j++)temp[i][j] = ident[i][j-n];
        int m = n*2;
        vector<int> where (m, -1);
        
        for (int col=0, row=0; col<m && row<n; ++col) {
            int sel = row;
            for (int i=row; i<n; ++i)
                if (abs (temp[i][col]) > abs (temp[sel][col]))
                    sel = i;
            if (abs (temp[sel][col]) < EPS)
                continue;
            for (int i=col; i<m; ++i)
                swap (temp[sel][i], temp[row][i]);
            where[col] = row;
            ld div = temp[row][col];
            for(int i = 0;i<m;i++)
                if(fabs(temp[row][i])>EPS)temp[row][i] /=div;
            for (int i=0; i<n; ++i)
                if (i != row) {
                    ld c = temp[i][col] / temp[row][col];
                    for (int j=col; j<m; ++j)
                        temp[i][j] -= temp[row][j] * c;
                }
            ++row;
        }
        for(int i = 0;i<n;i++)
            for(int j = 0;j<n;j++)
                inverse[i][j] = temp[i][j+n];
        return true;
    }
    //Adjoint
    Matrix<T> mn(int x, int y){
        Matrix<T> M(r-1, c-1);
        for(int i = 0; i < c-1; ++i)
            for(int j = 0; j < r-1; ++j)
                M[i][j] = A[i < x ? i : i+1][j < y ? j : j+1];
        return M;
    }
    T cofactor(int x, int y){
        T ans = mn(x, y).detGauss();
        if((x + y) % 2 == 1) ans *= -1;
        return ans;
    }
    Matrix<T> cofactorMatrix(){
        Matrix<T> C(r, c);
        for(int i = 0; i < c; i++)
            for(int j = 0; j < r; j++)
                C[i][j] = cofactor(i, j);
        return C;
    }
    Matrix<T> Adjunta(){
        int n = A[0].size();
        Matrix<int> adjoint(n);
        Matrix<ld> inverse(n);
        this->Inverse(inverse);
        int determinante = this->detGauss();
        if(determinante){
            for(int i = 0;i<n;i++)
                for(int j = 0;j<n;j++)  
                    adjoint[i][j] = (T)round((inverse[i][j]*determinante));
        }
        else {
            adjoint = this->cofactorMatrix().transpose();
        }
        return adjoint;    
    }

    //Transpuesta
    Matrix transpose(){
        Matrix <T> C(c,r);
        int i,j;
        for(i=0;i<r;i++)
            for(j=0;j<c;j++)
                C[j][i] = A[i][j];

        return C;
    }
    //Traza
    T trace(){
        T sum = 0;
        for(int i = 0; i < min(r, c); i++)
            sum += A[i][i];
        return sum;
    }
    //Determinante
    int determinant() {
        int n = r;
        Matrix<T> temp(n);
        temp.A = A;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                temp[i][j] %= mod;
        lli res = 1;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (; temp[j][i]; res = -res) {
                    long long t = temp[i][i] / temp[j][i];
                    for (int k = i; k < n; k++) {
                        temp[i][k] = (temp[i][k] - temp[j][k] * t) % mod;
                        std::swap(temp[j][k], temp[i][k]);
                    }
                }
            }
            if (temp[i][i] == 0)
                return 0;
            res = res * temp[i][i] % mod;
        }
        if (res < 0)
            res += mod;
        return static_cast<int>(res);
    }
    int detGauss(){
        assert(r == c);
        ld det = 1;
        Matrix<ld> temp(r);
        temp.r = r;
        temp.c = c;
        int n = r;
        for(int i = 0;i<n;i++)
            for(int j = 0;j<n;j++)
                temp[i][j] = (ld)A[i][j];
        for (int i=0; i<n; ++i) {
            int k = i;
            for (int j=i+1; j<n; ++j)
                if (fabs (temp[j][i]) > fabs (temp[k][i]))
                    k = j;
            if (abs (temp[k][i]) < EPS) {
                det = 0;
                break;
            }
            swap (temp[i], temp[k]);
            if (i != k)
                det = -det;
            det *= temp[i][i];
            for (int j=i+1; j<n; ++j)
                temp[i][j] /= temp[i][i];
            for (int j=0; j<n; ++j)
                if (j != i && abs (temp[j][i]) > EPS)
                    for (int k=i+1; k<n; ++k)
                        temp[j][k] -= temp[i][k] * temp[j][i];
        }
        return (int)det;
    }
    

    int gauss (vector<ld> & ans) {
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

int main(){
    int n,t,u,v,c,s,e;
    cin>>t;
    cout<<fixed<<setprecision(5);
    while(t--){
        cin>>n>>s>>e;
        s--,e--;
     
        Matrix<int> graph(n);
        vector<int> ac(n);
        for(int i = 0;i<n-1;i++){
            cin>>u>>v>>c;  
            u--,v--;
            graph[u][v] = c;
            graph[v][u] = c;
            ac[u]+=c;
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
    }
    return 0;
}