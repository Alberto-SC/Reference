#include <bits/stdc++.h>
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n';

using namespace std;

const int mod = 1e9+7;

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
                    (C[i][j] += (A[i][k] * B[k][j])%mod)%=mod;
                }
            }
        }
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


signed main(){__
    int T,k,n;
    cin>>k>>n;
    Matrix<int> M(k,k);

    for(int i= 1;i<=k;i++){
        for(int j = 1;j<=k;j++){
            if(__gcd(i,j)==1)
                M[i-1][j-1] = 1;
        }
    }


    M^=n;
    int ans = 0;
    for(int i = 0;i<k;i++){
        ans+=M[0][i];
        ans%=mod;
    }
    cout<<ans<<endl;
    return 0;
}

