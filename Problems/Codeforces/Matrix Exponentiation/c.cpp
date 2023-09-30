#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define INF INT_MAX
const double EPS = 1e-9;
typedef long long int lli;
template <typename T>
struct Matrix {
    vector < vector <T> > A;
    int r,c;

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
        Matrix <T> C(r,B.c,0);
        for(int i=0 ; i<r ; i++)
            for(int j=0 ; j<B.c ; j++)
                for(int k=0 ; k<c ; k++)
                    C[i][j] = (C[i][j] + ( (long long )A[i][k] * (long long)B[k][j] ))%mod;
        return C;
    }
    Matrix operator ^ (long long n){
        Matrix <T> C(r);
        Matrix <T> X(r,c,0);
        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++)
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
    void operator ^= (long long n){
        (*this)  =(*this)^n;
    }
};


int main(){
    lli n;
    cin>>n;
    Matrix<lli> m(2,2,1);
    m[1][1] = 0;
    Matrix<lli> b(2,1,0);
    b[1][0] = 1;
    m^=n;
    m*=b;
    cout<<m[0][0]<<endl;
    return 0;
}