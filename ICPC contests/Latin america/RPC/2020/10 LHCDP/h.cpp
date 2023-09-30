
#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
const lli mod = 1e9+7;

struct Matrix{
    vector<vector<lli>> A;
    int r,c;
    Matrix(int n,int m){
        A.resize(n,vector<lli> (m,0));
        r = n;
        c = m;
    } 
    Matrix(int n){
        A.resize(n,vector<lli>(n,0));
        for(int i = 0;i<n;i++)A[i][i] = 1;
        r = c = n;
    }
    Matrix(int n,int m,int v){
        A.resize(n,vector<lli>(m,v));
        r = n;
        c = m;
    }
    Matrix operator * (const Matrix B){
        Matrix res(r,B.c,0);
        for(int i = 0;i<r;i++)
            for(int j = 0;j<B.c;j++)
                for(int k = 0;k<c;k++)
                    res[i][j]=(res[i][j] + (A[i][k]*B[k][j])),res[i][j]>=8*mod*mod?res[i][j]%=mod:0;
        for(int i = 0;i<r;i++)for(int j = 0;j<B.c;j++)res[i][j]%=mod;
        return res;
    }
    void operator *=(const Matrix B){
        (*this) = (*this)*B;
    }
    Matrix operator ^(lli p){
        Matrix id(c);
        Matrix res(r,c);
        for(int i = 0;i<r;i++)for(int j = 0;j<c;j++)res[i][j] =A[i][j];
        while(p){
            if(p&1) id*=res;
            res*=res;
            p>>=1;
        }
        return id;
    }
    void operator ^=(lli n){
        (*this)= (*this)^n;
    }
    vector<lli>& operator [](int i){
        return A[i];
    }
    const vector<lli>&  operator [](int i)const{
        return A[i];
    }
    friend ostream& operator <<(ostream &out ,const Matrix &M){
        for(int i = 0;i<M.r;i++)
            for(int j = 0;j<M.c;j++)
                out<<M[i][j]<<" \n"[j == M.c-1];
        return out; 
    }
};

Matrix gen_base(string s,string m){
    int n = m.size(); 
    Matrix x(n+1);
    for(int i = 0;i<s.size();i++){
        for(int j = n-1;j>=0;j--){
            if(m[j] == s[i]){
                for(int k = 0;k<n;k++){
                    x[j+1][k] += x[j][k];
                    if(x[j+1][k]>=mod)x[j+1][k]-=mod;
                }
            }
            // cout<<x<<endl;
        }
    }
    return x;
}

int main(){
    lli n,sm;
    string s,m;
    cin>>s>>n>>m;
    Matrix M(1,1);
    M = gen_base(s,m);
    cout<<M<<endl;
    M^=n;
    cout<<M<<endl;
    cout<<M[m.size()][0]<<endl;
    return  0;
}