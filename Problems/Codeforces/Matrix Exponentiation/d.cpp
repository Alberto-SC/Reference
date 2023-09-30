#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
typedef long long int lli;
template<typename T>
struct Matrix{
    vector<vector<T>> A;
    int r,c;
    Matrix(int r,int c,T val){
        this->r = r;
        this->c = c;
        A.assign(r,vector<T> (c,val));
    }
    Matrix(int n){
        this->r = this->c = n;
        A.assign(n,vector<T> (n));
        for(int i = 0;i<n;i++)A[i][i] = 1;
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
        for(int i = 0;i<r;i++)for(int j = 0;j<c;j++)C[i][j]%=mod;
        return C;
    }
    Matrix operator ^(lli n){
        Matrix<T> X(r);
        Matrix<T> C(r,c,0);
        for(int i = 0;i<r;i++)
            for(int j= 0;j<c;j++)C[i][j] = A[i][j];
        while(n){
            if(n&1)X *= C;
            C*=C;
            n>>=1;
        }
        return X;
    }
    void operator ^=(lli n){
        (*this) = (*this)^n;
    }
    void operator *=(const Matrix<T> B){
        (*this) = (*this)*B;
    }

    const vector<T>& operator[](int i)const{
        return A[i];
    }
    vector<T>& operator[](int i){
        return A[i];
    }
    friend ostream& operator<<(ostream &out,const Matrix<T> &M){
        for(int i = 0;i<M.r;i++)
            for(int j = 0;j<M.c;j++)
                out<<M[i][j]<<" \n"[j == M.c-1];
        return out;
    }
};
int main(){
    int n,m,k,u,v;
    cin>>n>>m>>k;
    Matrix<lli> graph(n,n,0);
    for(int i = 0;i<m;i++){
        cin>>u>>v;
        u--,v--;
        graph[u][v] = 1;
    }
    graph^=k;
    // cout<<graph<<endl;
    lli ans = 0;
    for(int i = 0;i<n;i++)
        for(int j = 0;j<n;j++){
            ans+=graph[i][j];
            ans%=mod;
        }
    cout<<ans<<endl;

    return 0;
}