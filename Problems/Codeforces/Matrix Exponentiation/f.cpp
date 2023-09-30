#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
const lli INF = 3e18;
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
        Matrix<T> C(r,B.c,INF);
        for(int i = 0;i<r;i++){
            for(int j = 0;j<B.c;j++){
                for(int k = 0;k<c;k++){
                    C[i][k] = min(C[i][k] ,A[i][j] +B[j][k]);
                }
            }
        }
        return C;
    }
    Matrix operator ^(lli n){
        Matrix<T> X(r,r,INF);
        for(int i = 0;i<r;i++)X[i][i] = 0;
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
    int n,m,k,u,v,c;
    cin>>n>>m>>k;
    Matrix<lli> graph(n,n,INF);
    for(int i = 0;i<m;i++){
        cin>>u>>v>>c;
        u--,v--;
        graph[u][v] = c;
    }
    graph^=k;
    // cout<<graph<<endl;
    lli ans = INF;
    for(int i = 0;i<n;i++)
        for(int j = 0;j<n;j++)
            ans = min(ans,graph[i][j]);
    
    if(ans>=INF/2)cout<<"IMPOSSIBLE"<<endl;
    else
        cout<<ans<<endl;

    return 0;
}