#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long int lli;
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
        assert(c == B.r);
        int i,j,k;
        int x = r;
        int y = c;
        int z = B.c;
        Matrix<T> C(x,z,0);
        for(int i = 0;i<x;i++)
            for(int j = 0;j<z;j++)
                for(int k = 0;k<c;k++)
                    C[i][j] = (C[i][j]+
                    ((A[i][k]%(mod-1))*(B[k][j]%(mod-1))%(mod-1)))%(mod-1);
        return C;
    }
    Matrix operator ^ (lli n){
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
    void operator ^= (lli n){
        (*this) = (*this)^n;
    }
};


int powmod(int a, int b, int m) {
    int res = 1;
    while (b > 0) {
        if (b & 1) {
            res = (res * 1ll * a) % m;
        }
        a = (a * 1ll * a) % m;
        b >>= 1;
    }
    return res;
}

int dislog(int a, int b, int m) {
    int n = (int) sqrt (m + .0) + 1;
    map<int, int> vals;
    for (int p = n; p >= 1; --p)
        vals[powmod(a, p * n, m)] = p;
    for (int q = 0; q <= n; ++q) {
        int cur = (powmod(a, q, m) * 1ll * b) % m;
        if (vals.count(cur)) {
            int ans = vals[cur] * n - q;
            return ans;
        }
    }
    return -1;
}
int main(){
    lli n,f0,f1,f2,c;
    cin>>n>>f0>>f1>>f2>>c;
    f0 = dislog(5,f0,mod);
    f1 = dislog(5,f1,mod);
    f2 = dislog(5,f2,mod);
    c = dislog(5,c,mod);
    // f0 = 0;
    // f2 = 1;
    // cout<<f0<<" "<<f1<<" "<<f2<<" "<<c<<endl;
    Matrix<lli> M(5,5);
    M[0][0] = 1;
    M[1][0] = 1;
    M[1][1] = 1;
    M[2][3] = 1;
    M[3][4] = 1;
    M[4][2] = M[4][3] = M[4][4] = 1;
    M[4][0] = -6*c;
    M[4][1] = c*2;
    Matrix<lli> T(5,1);
    T[0][0] = 1;
    T[1][0] = 4;
    T[2][0] = f0;
    T[3][0] = f1;
    T[4][0] = f2;
    // cout<<M<<endl;
    M^=(n-3);
    // cout<<M<<endl;
    // cout<<T<<endl;
    M*=T;
    // cout<<M<<endl;
    lli ans = powmod(5,M[4][0],mod);
    cout<<ans<<endl;
    return 0;
}