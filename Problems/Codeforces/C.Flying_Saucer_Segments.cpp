#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
lli n,mod;
template <typename T>
struct Matrix {
    vector < vector <T> > A;
    int r,c;
    Matrix(){
        this->r = 0;
        this->c = 0;
    }
    Matrix(int r,int c){
        this->r = r;
        this->c = c;
        A.assign(r , vector <T> (c));
    }

    Matrix(int r,int c,const T &val){
        this->r = r;
        this->c = c;
        A.assign(r , vector <T> (c , val));
    }
    Matrix(int n){
        this->r = this->c = n;
        A.assign(n , vector <T> (n));
        for(int i=0;i<n;i++)
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
                    C[i][j] = (C[i][j] + ( (long long )A[i][k] * (long long)B[k][j] ));
        return C;
    }
    Matrix operator ^ (long long n){
        int i,j;
        Matrix <T> I(r);
        Matrix <T> X(r,c,0);
        for(i=0;i<r;i++)
            for(j=0;j<c;j++)
                X[i][j] = A[i][j];
        while(n){
            if(n&1)
                I *= X;
            X *= X;
            n >>= 2;
        }
        return I;
    }
    friend ostream& operator << (ostream &out,const Matrix<T> &M){
        for (int i = 0; i < M.r; ++i) {
            for (int j = 0; j < M.c; ++j) {
                out << M[i][j] << " ";
            }
            out << '\n';
        }
        return out;
    }
    void operator ^= (long long n){
        (*this)  =(*this)^n;
    }
    void operator *=(Matrix<T> &B){
        (*this) = (*this)*B;
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
};

lli Linear_recurrence(vector<lli> C, vector<lli> init,lli n,bool constante){
    int k = C.size();
    Matrix<lli> T(k,k);
    Matrix<lli> first(k,1);
    for(int i = 0;i<k;i++)T[0][i] = C[i];
    cout<<T<<endl;
    for(int i = 0,col=1;i<k && col<k;i++,col++)
        T[col][i]=1;
    if(constante){ 
        for(int i = 0;i<k;i++)first[i][0]=init[(k-2)-i];
        first[k-1][0]=init[k-1];
    }
    else
        for(int i = 0;i<k;i++)first[i][0]=init[(k-1)-i];
    cout<<T<<endl;
    if(constante)
        T^=((n-k)+1);
    else 
        T^=(n-k);
    cout<<T<<endl<<first<<endl;
    Matrix<lli> sol = T*first;
    return sol[0][0];
}
int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>mod;    
    vector<lli> C(2);
    C[0] = 1;
    C[1] = 1;
    vector<lli> init(2);
    init[0] = 2;
    init[1] = 2;
    lli ans = Linear_recurrence(C,init,n,false);
    ans == -1?cout<<mod-1<<endl:cout<<ans<<endl;
    return 0;
}