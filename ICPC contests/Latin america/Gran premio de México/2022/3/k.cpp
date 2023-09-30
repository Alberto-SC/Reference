#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

int f[11][401];
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

set<int> poss;
Matrix<int> M(10,10);
Matrix<int> T(10,1);

int dp(int n){
  if(n<0)return 0;
  if(n ==0)return 1;
  int ans = 0;
  for(auto c:poss){
    ans+=f[c][0]*dp(n-c);
  } 
  return ans;
}

map<int,int> DP[401];

int get(int n){
  cout<<"GET: "<<n<<endl;
  if(n<=10)return T[n-1][0];
  else{
    Matrix<int> X = M^(n-10);
    X*=T;
    return X[0][0];
  }
}

int solve(int n,int k){
  if(n<0)return 0;
  if(n == 0)return 1;
  if(k<0)return 0;

  int &x = DP[k][n];
  int ans = get(n);
  cout<<ans<<endl;
  for(int i = 1;i<=10;i++){
    for(int j = 1;j<=400;j++){
      if(!f[i][j])continue;
      ans+=f[i][j]* solve(n-i,k-j);
    }
  }
  return ans;
}


signed main(){
  int n,m,k,d,p;
  cin>>n>>m>>k;
  for(int i = 0;i<m;i++){
    cin>>d>>p;
    f[d][p]++;
    if(p ==0)
      poss.insert(d);
  }

  for(int i = 1;i<=10;i++){
    T[i-1][0] = dp(11-i);
    cout<<T[i-1][0]<<" ";
  } 
  cout<<endl;
  for(int i = 1;i<=10;i++){
    if(poss.count(i))
      M[0][i-1] = 1;
    if(i!=10)
      M[i][i-1] = 1;
  }

  cout<<M<<endl;
  cout<<T<<endl;
  cout<<solve(n-1,k)<<endl;
  return 0;
}
