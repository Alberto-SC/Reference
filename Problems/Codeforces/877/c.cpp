#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

const int N = 1000007;
int lp[N+1];
vector<int> primes;
void criba(){
    for (int i=2; i<=N; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            primes.push_back (i);
        }
        for (int j=0; j<(int)primes.size() && primes[j]<=lp[i] && i*primes[j]<=N; ++j)
            lp[i * primes[j]] = primes[j];
    }
}

signed main(){__
  int T = 1,n,m;
  cin>>T;
  criba();
  vector<int> noPrimes;
  noPrimes.push_back(1);

  for(int i = 2;i<N;i++)
    if(lp[i]!=i)noPrimes.push_back(i);
  
  while(T--){
    cin>>n>>m;

    set<int> st;
    for(int i = 2;i<=n*m;i++)
      st.insert(i);

    vector<vector<int>> ans(n,vector<int>(m,-1));
    ans[0][0] = 1;


    for(int i = 0;i<n;i++){
      for(int j = 0;j<m;j++){
        if(j+1<n){
          for(auto nP:noPrimes){
            if(st.count(ans[i][j]+nP)){
              ans[i][j+1] = ans[i][j] + nP;
              break;
            }
            if(st.count(ans[i][j]-nP)){
              ans[i][j+1] = ans[i][j] - nP;
              break;
            }
          }
          st.erase(ans[i][j+1]);
        }
        if(i+1<n){
          for(auto nP:noPrimes){
            if(st.count(ans[i][j]+nP)){
              ans[i+1][j] = ans[i][j] + nP;
              break;
            }
            if(st.count(ans[i][j]-nP)){
              ans[i+1][j] = ans[i][j] - nP;
              break;
            }
          }
          st.erase(ans[i+1][j]);
        }
      }
    }
    for(auto d:ans){
      for(auto c:d)cout<<c<<" ";
      cout<<endl;
    }
  }
  return 0;
}