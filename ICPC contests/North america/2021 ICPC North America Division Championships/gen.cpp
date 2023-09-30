#include <bits/stdc++.h>
using namespace std;
#define int long long
#define accuracy chrono::steady_clock::now().time_since_epoch().count()
#define rep(i,a,n) for (int i = a; i <= n; ++i)

const int N = 1e6 + 4;

int32_t permutation[N];

mt19937 rng(accuracy);

int rand(int l, int r){
  uniform_int_distribution<int> ludo(l, r); return ludo(rng);
}

signed main(){
  int n = 1000;
  cout<<n<<endl;
  for(int i = 0;i<n;i++){
    string s(100,'a');
    for(int j = 0;j<100;j++){
      //s[j] = char(rand(0,26)+'a');
      s[j] = 'a';
    }
    cout<<s<<endl;
  }
  cout<<endl;
  return 0;
}
