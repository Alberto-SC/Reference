#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
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
        assert(c == B.r);
        int i,j,k;
        int x = r;
        int y = c;
        int z = B.c;
        Matrix <T> C(x,z,0);
        for(i=0 ; i<x ; i++)
            for(j=0 ; j<z ; j++)
                for(k=0 ; k<y ; k++)
                    C[i][j] = (C[i][j] + ( (long long )A[i][k] * (long long)B[k][j] ))%mod;
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

};

int main(){
    lli n;
    cin>>n;
    Matrix<lli> m(2,2);
    m[0][0] = 19;
    m[0][1] = 7;
    m[1][0] = 6;
    m[1][1] = 20; 
    m^=n;
    cout<<m[0][0]<<endl;
    return 0;
}