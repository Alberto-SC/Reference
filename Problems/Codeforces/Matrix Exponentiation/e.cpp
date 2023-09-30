#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
const lli mod = 1ll<<32; 
bool check(int u,int v){
    if(u<0 || u>=8)return false;
    if(v<0 || v>=8)return false;
    return true;
}
int fx[] = {+1,+2,+2,+1,-1,-2,-2,-1};
int fy[] = {-2,-1,+1,+2,+2,+1,-1,-2};
template<typename T>
struct Matrix{
    vector<vector<T>> A;
    int r,c;
    Matrix(int n){
        this->r = this->c = n;
        A.assign(n,vector<T>(n));
        for(int i = 0;i<n;i++)A[i][i] = 1;
    }
    Matrix(int r,int c,T val){
        this->r = r;
        this->c = c;
        A.assign(r,vector<T> (c,val));
    }
    Matrix operator *(const Matrix<T> B){
        Matrix<T> C(r,B.c,0);
        for(int i =0;i<r;i++)
            for(int j = 0;j<B.c;j++)
                for(int k = 0;k<c;k++)
                    C[i][j] = (C[i][j] + (A[i][k]* B[k][j]));
        return C;
    }
    Matrix operator ^(lli n){
        Matrix<T> X(r);
        Matrix<T> C(r,c,0);
        for(int i = 0;i<r;i++)
            for(int j = 0;j<c;j++)
                C[i][j] = A[i][j];
        while(n){
            if(n&1)X*=C;
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
    vector<T> & operator[](int i){
        return A[i];
    }
    friend ostream& operator <<(ostream &out ,const Matrix<T> &M){
        for(int i = 0;i<M.r;i++)
            for(int j = 0;j<M.c;j++)
                out<<M[i][j]<<" \n"[j == M.c-1];
        return out;
    }
};
int main(){
    lli k;
    cin>>k;
    k++;
    Matrix<unsigned int> graph(65,65,0);
    for(int i = 0;i<8;i++){
        for(int j = 0;j<8;j++){
            int nx = i,ny = j;
            for(int k = 0;k<8;k++){
                nx = i+fx[k];
                ny = j+fy[k];
                if(check(nx,ny))graph[(i*8)+j][(nx*8)+ny]=1;
            }
        }
    }
    for(int i = 0;i<=64;i++)
        graph[i][64] = 1;

    graph^=k;
    cout<<graph[0][64]<<endl;

    return 0;
}