/**
 * Author: Alberto Silva
 * Description: A template for Matrix structure with all basic operations
 * like exponensation ,sum , rest, determinant ,reduction by gauss etc
 * Usage: Matrix<type> M
 */
#define mod 1e9+7
#define INF INT_MAX
const double EPS = 1e-9;
typedef long long int lli;
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
    bool Inverse(Matrix<double> &inverse){
        if(this->detGauss() == 0)return false;
        int n = A[0].size();
        Matrix<double> temp(n,2*n);
        for(int i = 0;i<n;i++)
            for(int j = 0;j<n;j++)temp[i][j] =  A[i][j]; 
        Matrix<double> ident(n);
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
            double div = temp[row][col];
            for(int i = 0;i<m;i++)
                if(fabs(temp[row][i])>EPS)temp[row][i] /=div;
            for (int i=0; i<n; ++i)
                if (i != row) {
                    double c = temp[i][col] / temp[row][col];
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
    Matrix<T> minor(int x, int y){
        Matrix<T> M(r-1, c-1);
        for(int i = 0; i < c-1; ++i)
            for(int j = 0; j < r-1; ++j)
                M[i][j] = A[i < x ? i : i+1][j < y ? j : j+1];
        return M;
    }
    T cofactor(int x, int y){
        T ans = minor(x, y).detGauss();
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
        Matrix<double> inverse(n);
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
        double det = 1;
        Matrix<double> temp(r);
        temp.r = r;
        temp.c = c;
        int n = r;
        for(int i = 0;i<n;i++)
            for(int j = 0;j<n;j++)
                temp[i][j] = (double)A[i][j];
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

    int gauss (vector<double> & ans) {
        Matrix<double> Temp(this->r,this->c);
        int n = (int) Temp.A.size();
        int m = (int) Temp[0].size() - 1;
        for(int i = 0;i<n;i++)
            for(int j = 0;j<n;j++)
                Temp[i][j] = (double)A[i][j];
        
        vector<int> where (m, -1);
        for (int col=0, row=0; col<m && row<n; ++col) {
            int sel = row;
            for (int i=row; i<n; ++i)
                if (fabs (Temp[i][col]) > fabs (Temp[sel][col]))
                    sel = i;
            if (fabs (Temp[sel][col]) < EPS)
                continue;
            for (int i=col; i<m; ++i)
                swap (Temp[sel][i], Temp[row][i]);
            where[col] = row;

            for (int i=0; i<n; ++i)
                if (i != row) {
                    double c = Temp[i][col] / Temp[row][col];
                    for (int j=col; j<m; ++j)
                        Temp[i][j] -= Temp[row][j] * c;
                }
            ++row;
        }
        ans.assign (m, 0);
        for (int i=0; i<m; ++i)
            if (where[i] != -1)
                ans[i] = Temp[where[i]][m] / Temp[where[i]][i];
        for (int i=0; i<n; ++i) {
            double sum = 0;
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
    /*+ Kirchhoff Matrix Tree Theorem Describe in Graphs -> Math */
    int Kirchof(){
        cin>>n>>m>>k;
        Matrix<lli> Kirchof(n);
        for(int i = 0;i<m;i++){
            cin>>a>>b;
            a--;
            b--;
            Kirchof[a][b] = Kirchof[b][a] = 1;
            Kirchof[a][a]++;
            Kirchof[b][b]++;
        }
        for(int i =0;i<n;i++)
            Kirchof[i][i] = (1ll*n*k%mod-Kirchof[i][i]+mod)%mod;
        lli ans = 1;
        ans = ans*(mod_pow(1ll*k*n%mod*k%mod*n%mod,mod-2));
        lli determinante =Kirchof.det();
        ans  = ans*(mod_pow(determinante,k))%mod;
        cout<<ans<<endl;
    }
};

/*+     [f(n)]          [1 1 1 1 1 1]      [f(5)]
        [f(n-1)]        [1 0 0 0 0 0]      [f(4)]
        [f(n-2)]        [0 1 0 0 0 0]      [f(3)]
        [f(n-3)]        [0 0 1 0 0 0]      [f(2)]
        [f(n-4)]        [0 0 0 1 0 0]      [f(1)]
        [(e]]           [0 0 0 0 1 0]      [ e ]

*/
lli Linear_recurrence(vector<lli> C, vector<lli> init,lli n,bool constante){
    int k = C.size();
    Matrix<lli> T(k,k);
    Matrix<lli> first(k,1);
    for(int i = 0;i<k;i++)T[0][i] = C[i];
    for(int i = 0,col=1;i<k && col<k;i++,col++)
        T[col][i]=1;
    if(constante){ 
        for(int i = 0;i<k;i++)first[i][0]=init[(k-2)-i];
        first[k-1][0]=init[k-1];
    }
    else
        for(int i = 0;i<k;i++)first[i][0]=init[(k-1)-i];
    if(constante)
        T^=((n-k)+1);
    else 
        T^=(n-k);
    Matrix<lli> sol = T*first;
    return sol[0][0];

    //Example Tribonacci F(i) = 1*F(i-1) + 1*F(i-2) + 1*F(i-3) + (c= 0)
    // vector<lli>C(3);
    // C[0] =1;
    // C[1] =1;
    // C[2] =1;
    // vector<lli> ini(3);
    // ini[0] =1;
    // ini[1] =1;
    // ini[2] =2;
    // cout<<Linear_recurrence(C,ini,nth,false)<<endl;
}

// exclude-from-here
int main(){
    int n;
    cin>>n;
    Matrix<int> Example(n);
    for(int i = 0;i<n;i++)
        for(int j = 0;j<n;j++)cin>>Example[i][j]; 
    Example ^= 2;
    cout<<Example<<endl;
    cout<<Example.detGauss()<<endl;
    vector<double> sol;
    Matrix<double>inverse(n); 
    if(Example.Inverse(inverse)){
       cout<<"Has inverse"<<endl;
       cout<<inverse<<endl;
    }
    else cout<<"No inverse"<<endl;
    if(Example.gauss(sol)){
        cout<<"Has solution"<<endl;
        for(auto c: sol)cout<<c<<endl;
        
    }
    else cout<<"No solution"<<endl;
    cout<<"Adjoint"<<endl;
    Matrix<int> Adjoint = Example.Adjunta();
    cout<<Adjoint<<endl;

    // cout<<solveRecurrence(C,ini,6);
    // cin>>n
    // Matrix<lli> GaussE(n);
    // gauss(GaussE,sol);
    // Matrix<int> adjunta = GaussE;
    // Matrix<double> InverseGauss;
    // InverseGauss = Inverse(GaussE);
    // cout<<InverseGauss<<endl;
    // // adjunta = adjunta(adjunta);
    // cout<<adjunta<<endl;
    // adjunta = Adjunta(adjunta);
    // cout<<adjunta<<endl;
    // for(auto c:sol)cout<<c<<endl;

}
// 1 1 5 9 17
// 1 1 3 5 9 15
// 1 1 2 4 7 13 24 44 81
// 1 1 3 5 9 17



//FOR MATRIX EXPONENTIATION ONLY 

#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
const lli mod = 1e9+7;

struct Matrix{
    vector<vector<lli>> A;
    int r,c;
    Matrix(int n,int m){
        A.resize(n,vector<lli> (m,0));
        r = n;
        c = m;
    } 
    Matrix(int n){
        A.resize(n,vector<lli>(n,0));
        for(int i = 0;i<n;i++)A[i][i] = 1;
        r = c = n;
    }
    Matrix(int n,int m,int v){
        A.resize(n,vector<lli>(m,v));
        r = n;
        c = m;
    }
    Matrix operator * (const Matrix B){
        Matrix res(r,B.c,0);
        for(int i = 0;i<r;i++)
            for(int j = 0;j<B.c;j++)
                for(int k = 0;k<c;k++)
                    res[i][j]=(res[i][j] + (A[i][k]*B[k][j])),res[i][j]>=8*mod*mod?res[i][j]%=mod:0;
        for(int i = 0;i<r;i++)for(int j = 0;j<B.c;j++)res[i][j]%=mod;
        return res;
    }
    void operator *=(const Matrix B){
        (*this) = (*this)*B;
    }
    Matrix operator ^(lli p){
        Matrix id(c);
        Matrix res(r,c);
        for(int i = 0;i<r;i++)for(int j = 0;i<c;j++)res[i][j] =A[i][j];
        while(p){
            if(p&1) id*=res;
            res*=res;
            p>>=1;
        }
        return id;
    }

    vector<lli>& operator [](int i){
        return A[i];
    }
    const vector<lli>&  operator [](int i)const{
        return A[i];
    }
    friend ostream& operator <<(ostream &out ,const Matrix &M){
        for(int i = 0;i<M.r;i++)
            for(int j = 0;j<M.c;j++)
                out<<M[i][j]<<" \n"[j == M.c-1];
        return out; 
    }
};

