#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
typedef long double ld;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
const ld mod = 2147483647;

struct Matrix{
    vector<vector<ld>> A;
    int r,c;
    Matrix(int n,int m){
        A.resize(n,vector<ld> (m,0));
        r = n;
        c = m;
    } 
    Matrix(int n){
        A.resize(n,vector<ld>(n,0));
        for(int i = 0;i<n;i++)A[i][i] = 1.0;
        r = c = n;
    }
    Matrix(int n,int m,int v){
        A.resize(n,vector<ld>(m,v));
        r = n;
        c = m;
    }
    Matrix operator * (const Matrix B){
        Matrix res(r,B.c,0);
        for(int i = 0;i<r;i++)
            for(int j = 0;j<B.c;j++)
                for(int k = 0;k<c;k++)
                    res[i][j]=fmodl((res[i][j] + (A[i][k]*B[k][j])),mod);
        return res;
    }
    void operator *=(const Matrix B){
        (*this) = (*this)*B;
    }
    Matrix operator ^(lli p){
        Matrix id(c);
        Matrix res(r,c);
        for(int i = 0;i<r;i++){
            for(int j = 0;j<c;j++){
                res[i][j] =A[i][j];
            }
        }
        while(p){
            if(p&1) id*=res;
            res*=res;
            p>>=1;
        }
        return id;
    }
    void operator ^= (lli n){
        (*this)  =(*this)^n;
    }
    vector<ld>& operator [](int i){
        return A[i];
    }
    const vector<ld>&  operator [](int i)const{
        return A[i];
    }
    friend ostream& operator <<(ostream &out ,const Matrix &M){
        for(int i = 0;i<M.r;i++)
            for(int j = 0;j<M.c;j++)
                out<<M[i][j]<<" \n"[j == M.c-1];
        return out; 
    }
};


int main(){__
    lli t,n;
    cin>>t;
    Matrix b(4,4);
    b[0][0] = 1;
    b[0][1] = 0;
    b[0][2] = 0.5;
    b[0][3] = 0.5;
    b[1][0] = 0;
    b[1][1] = 1;
    b[1][2] = 0;
    b[1][3] = 0;
    b[2][0] = 0;
    b[2][1] = 1;
    b[2][2] = 1;
    b[2][3] = 0;
    b[3][0] = 0;
    b[3][1] = 1;
    b[3][2] = 2;
    b[3][3] = 1;
    Matrix T(4,1);
    T[0][0] = 1;
    T[1][0] = 1;
    T[2][0] = 2;
    T[3][0] = 4;
    cout<<fixed<<setprecision(0);
    vector<Matrix> pows;
    pows.push_back(b);
    for(int i = 1;i<=60;i++){
        pows.push_back(pows[i-1]*pows[i-1]);
    }

    // for(int i = 0;i<5;i++){
        // cout<<pows[i]<<endl;
    // }
    cout<<endl;
    while(t--){
        cin>>n;
        n--;
        Matrix idt(4);
        for(int i = 59;i>=0;i--){
            if((n>>i)&1ll){
                idt*=pows[i];
            }
        }
        idt*=T;
        cout<<idt[0][0]<<endl;
    }

}