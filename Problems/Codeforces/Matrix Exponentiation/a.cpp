#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
template<typename T>
struct Matrix{
    vector<vector<T>> A;
    int n;
    Matrix(int n){
        this->n = n;
        A.assign(n,vector<T>(n));
    }
    Matrix operator *(const Matrix<T> b){
        Matrix<T> C(this->n);
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                for(int k = 0;k<n;k++){
                    C[i][j] += A[i][k]*b[k][j];   
                }
            }
        }
        return C;
    }
    Matrix operator ^(int pw){
        Matrix<T> x(n);
        Matrix<T> B(n);
        for(int i = 0;i<n;i++)x[i][i] = 1;
        for(int i = 0;i<n;i++)
            for(int j = 0;j<n;j++) 
                B[i][j] = A[i][j];
        while(pw){
            if(pw&1)x*= B;
            B*=B;
            pw>>=1;
        }
        return x;
    }
    void operator ^=(int n){
        (*this)= (*this)^n;
    }
    void operator *=(const Matrix<T> B){
        (*this) = (*this)*B;
    }

    vector<T> & operator[](int i){
        return A[i];
    }
    const vector<T> & operator[](int i)const{
        return A[i];
    }

};

int main(){
    int n;
    ld p;
    cin>>n>>p;
    Matrix<ld> m(2);
    m[0][0] = 1.0-p;
    m[0][1] = p;
    m[1][0] = p;
    m[1][1] = 1.0-p;
    m^=n;
    cout<<setprecision(10);
    cout<<m[0][0]<<endl;
    return 0;
}