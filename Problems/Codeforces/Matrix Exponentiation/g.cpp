#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
const lli mod = 1e9+7;
template<typename T> 
struct Matrix{
    vector<vector<T>> A;
    int r,c;
    Matrix(int n){
        r = n;
        c = n;
        A.assign(n,vector<T>(n));
        for(int i = 0;i<n;i++)A[i][i] = 1;
    }
    Matrix(int r,int c,T val){
        this->r = r;
        this->c = c;
        A.assign(r,vector<T>(c,val));
    }

    Matrix operator * (const Matrix<T> B){

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
        for(int i = 0;i<r;i++)for(int j = 0;j<B.c;j++)C[i][j]%=mod;
        return C;
    }
    Matrix operator^(lli n){
        Matrix<T> x(r);
        Matrix<T> C(r,c,0);
        for(int i = 0;i<r;i++)for(int j = 0;j<c;j++)C[i][j] = A[i][j];
        while(n){
            if(n&1)x*= C;
            C*=C;
            n>>=1;
        }
        return x;
    }
    void operator ^= (lli n){
        (*this) = (*this)^n;
    }
    void operator *=(const Matrix<T> B){
        (*this) = (*this)*B;
    }
    const vector<T>& operator[](int i)const {
        return A[i];
    }
    vector<T> & operator[](int i){
        return A[i];
    }
    friend ostream& operator <<(ostream &out,Matrix<T> M){
        for(int i = 0;i<M.r;i++)
            for(int j = 0;j<M.c;j++)
                out<<M[i][j]<<" \n"[j == M.c-1];
        return out;
    }
};

int main(){
    lli n,k,p,q,r;
    cin>>n>>k;
    Matrix<lli> T(n+4,1,0);
    Matrix<lli> M(n+4,n+4,0);
    for(int i = 0;i<n;i++)
        cin>>T[(n-i)-1][0];
    T[n][0] = 1;
    T[n+1][0] = n;
    T[n+2][0] = 1;
    T[n+3][0] = n*n; 
    for(int i = 0;i<n;i++)
        cin>>M[0][i];

    cin>>p>>q>>r;
    if(k <n)return cout<<T[0][(n-k)-1]<<endl,0;
    M[0][n] = p;
    M[0][n+1] = q;
    M[0][n+2] = 0;
    M[0][n+3] = r;
    for(int i = 1;i<n;i++)
        M[i][i-1] = 1;

    M[n][n] = 1;
    M[n+1][n+1] = 1;
    M[n+1][n+2] = 1;
    M[n+2][n+2] = 1;
    M[n+3][n+3] = 1;
    M[n+3][n+2] = 1;
    M[n+3][n+1] = 2;
    // cout<<M<<endl;
    // cout<<T<<endl;
    M^=(k-n)+1;
    M*=T;
    // cout<<M<<endl;
    cout<<M[0][0]<<endl;
    return 0;
}