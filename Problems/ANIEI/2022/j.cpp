#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

const int mod = 700666007;

template<typename T>
struct Matrix{
    vector<vector<T>> A;
    int r,c;
    Matrix(int r,int c){
        this->r = r;
        this->c = c;
        A.assign(r,vector<T>(c));
    }
    Matrix(int r,int c,int val){
        this->r = r;
        this->c = c;
        A.assign(r,vector<T>(c,val));
    }
    Matrix(int n){
        this->r = n;
        this->c = n;
        A.assign(n,vector<T>(n));
        for(int i = 0;i<n;i++)A[i][i] = (T)1;
    }
    Matrix operator *(const Matrix<T> B){

        Matrix<T> C(r,B.c,0);
        for(int i = 0;i<r;i++){
            for(int j = 0;j<B.c;j++){
                for(int k = 0;k<c;k++){
                    C[i][j] = (C[i][j] + (A[i][k] * B[k][j]));
                    if(C[i][j]>= 8*mod*mod)
                        C[i][j]%=mod;
                }
            }
        }
        for(int i = 0;i<r;i++)for(int j = 0;j<B.c;j++)C[i][j]%=mod;
        return C;
    }
    Matrix operator ^ (int n){
        assert(r == c);
        Matrix <T> C(r);
        Matrix <T> X(r,c,0);
        for(int i = 0;i<r;i++)
            for(int j = 0;j<c;j++)
                X[i][j] = A[i][j];
        while(n){
            if(n&1)C*=X;
            X *=X;
            n >>=1;
        }
        return C;
    }
    vector<T>& operator [](int i){
        assert(i<r);
        assert(i>=0);
        return A[i];
    }
    const vector<T>& operator [](int i)const {
        assert(i<r);
        assert(i>=0);
        return A[i];
    }
    friend ostream& operator <<(ostream &out ,const Matrix<T> &M){
        for(int i = 0;i<M.r;i++){
            for(int j = 0;j<M.c;j++){
                out<<M[i][j]<<" ";
            }
            out<<"\n";
        }
        return out;
    }
    void operator *= (const Matrix<T> &B){
        (*this) = (*this)*B;
    }
    void operator ^= (int n){
        (*this) = (*this)^n;
    }
};

signed main(){
    int t,a,b;
    Matrix<int> M(4,4);
    M[0][0] = 1;
    M[0][1] = 1;
    M[1][1] = 2;
    M[1][2] = 1;
    M[2][2] = 1;
    M[2][3] = 1;
    M[3][2] = 1;

    Matrix<int> T(4,1);
    T[0][0] = 19;
    T[1][0] = 24;
    T[2][0] = 3;
    T[3][0] = 2;

    vector<int> ans(5);
    ans[1] = 1;
    ans[2] = 3;
    ans[3] = 8;
    ans[4] = 19;
    cin>>t;
    while(t--){
        cin>>a>>b;
        a--;
        int x,y;
        if(b<=4)
            x = ans[b];
        else{
            Matrix<int> A = M^(b+1)-5;
            A*=T;
            x = A[0][0];
        }
        if(a<=4)
            y = ans[a];
        else{
            Matrix<int> A = M^(a+1)-5;
            A*=T;
            y = A[0][0];
        }
        // cout<<x<<endl;
        cout<<x-y<<endl;
    }

    // cout<<M<<endl;
    
    return 0;
}
