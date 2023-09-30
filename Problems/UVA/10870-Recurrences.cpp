#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
int mod; 
template<typename T>
struct Matrix{
    vector<vector<T>> A;
    int r;
    int c;
    Matrix(int N,int M){
        A.assign(N,vector<T>(M,0));
        this->r = N;
        this->c = M;
    }
    Matrix(int N,int M,T value){
        A.assign(N,vector<T>(M,value));
        this->r = N;
        this->c = M;
    }
    Matrix(int N){
        this->r = N;
        this->c = N;
        A.assign(N,vector<T>(N));
        for(int i=0;i<r;i++)
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
                    C[i][j] = (C[i][j] + ( (long long )A[i][k] * (long long)B[k][j] )%mod)%mod;
        return C;
    }
    void operator *=(const Matrix<T> &B){
        (*this) = (*this)*B;
    }
    void operator ^= (lli n){
        assert(r == c);
        int i,j;
        Matrix<T> C(r);
        Matrix<T> X(r,c,0);
        while(n){
            if(n&1) C*=(*this);
            (*this) *= (*this);
            n>>=1;
        }
        this->A = C.A;
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
    friend ostream& operator <<(ostream &out,Matrix<T> &Mat){
        for(int i = 0;i<Mat.r;i++)
            for(int j = 0;j<Mat.c;j++)
                out<<Mat[i][j]<<" \n"[j == Mat.c-1];
        return out;
    }


};
lli linear_recurrence(vector<lli> C, vector<lli> init, lli n){
    int k = C.size();
    Matrix<lli> T(k,k);
    Matrix<lli> first(k,1);
    for(int i = 0 ;i<k;i++)T[0][i] =C[i];
    for(int i =0,col = 1;i<k &&col<k;i++,col++)
        T[col][i] = 1;
    for(int i = 0;i<k;i++)first[i][0] = init[(k-1)-i];
    T^=(n-k);
    Matrix<lli> sol(k,1);
    sol = T*first;
    return sol[0][0];
}
int main(){
    int d,n,m;
    while(cin>>d>>n>>m){
        if(n == 0 && d == 0 && m == 0)break;
        mod = m;
        vector<lli> C(d);
        vector<lli> init(d);
        for(auto &x: C)cin>>x;
        for(auto &x: init)cin>>x;
        cout<<linear_recurrence(C,init,n)<<endl;
    }
    return 0;
}