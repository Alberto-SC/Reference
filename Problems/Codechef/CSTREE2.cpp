#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define mod 998244353
lli mod_pow(lli a ,lli b){
    lli ans = 1;
    while(b){
        if(b&1) ans = ans*a%mod;
        a = a*a%mod;
        b>>=1;
    }
    return ans;
}
template<typename T>
struct Matrix{
    vector< vector<T> > A;
    int n;
    Matrix(int N){
        this->n = N;
        A.assign(n,vector<T>(n,0));
    }
    vector<T> &operator [](int i){
        assert(i<n);
        assert(i>=0);
        return A[i];
    }
    friend ostream& operator <<(ostream &out,Matrix<T> &M){
        for(int i = 0;i<M.n;i++)
            for(int j = 0;j<M.n;j++)
                out<<M[i][j]<<" \n"[j == M.n-1];
        return out;
    }

     int det() {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                A[i][j] %= mod;
        lli res = 1;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (; A[j][i]; res = -res) {
                    long long t = A[i][i] / A[j][i];
                    for (int k = i; k < n; k++) {
                        A[i][k] = (A[i][k] - A[j][k] * t) % mod;
                        std::swap(A[j][k], A[i][k]);
                    }
                }
            }
            if (A[i][i] == 0)
                return 0;
            res = res * A[i][i] % mod;
        }
        if (res < 0)
            res += mod;
        return static_cast<int>(res);
    }
};

int main(){
    int t,n,m,k,a,b; 
    cin>>t;
    while(t--){
        cin>>n>>m>>k;
        Matrix<lli> Kirchof(n);
        for(int i = 0;i<m;i++){
            cin>>a>>b;
            a--;
            b--;
            Kirchof[a][b] = Kirchof[b][a] = 1;
            Kirchof[a][a]++;
            Kirchof[b][b]++;
        }
        for(int i =0;i<n;i++)
            Kirchof[i][i] = (1ll*n*k%mod-Kirchof[i][i]+mod)%mod;
        lli ans = 1;
        ans = ans*(mod_pow(1ll*k*n%mod*k%mod*n%mod,mod-2));
        lli determinante =Kirchof.det();
        ans  = ans*(mod_pow(determinante,k))%mod;
        cout<<ans<<endl;
    }
    return 0;
}