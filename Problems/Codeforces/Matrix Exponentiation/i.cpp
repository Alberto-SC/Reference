// #pragma comment(linker, "/stack:200000000")
// #pragma GCC optimize("Ofast,no-stack-protector")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
const int mod = 1e9+7;
#define endl '\n'
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
        for(int i = 0;i<r;i++)for(int j = 0;j<B.c;j++)C[i][j]%=mod;
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

int main(){__
    int n,m,k,u,v,q;
    clock_t start = clock();
    cin>>n>>m>>q;
    Matrix<lli> graph(n,n,0);
    for(int i = 0;i<m;i++){
        cin>>u>>v;
        u--,v--;
        graph[u][v] = 1;
    }
    vector<Matrix<lli>> M(31,Matrix<lli> (n,n,0));
    M[0] = graph;
    for(int i = 1;i<=30;i++)
        M[i] = M[i-1]*M[i-1];

    for(int i = 0;i<q;i++){
        cin>>u>>v>>k;
        u--,v--;
        Matrix<lli> T(n,1,0);
        T[v][0] = 1;
        for(int j = 0;j<=30;j++)
            if(k&(1<<j))
                T=M[j]*T; 
        cout<<T[u][0]<<endl;
    }
    cout<<fixed<<setprecision(6);
	double duration = (clock() - start) / (double) CLOCKS_PER_SEC;
	// cout<<"TIME: "<<duration << "\n";
    return 0;
}