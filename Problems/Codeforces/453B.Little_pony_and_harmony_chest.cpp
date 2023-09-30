#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);

int N = 53;
vector<int> primes;
vector<int> lp(N+1);
vector<int> M(N+1);
void criba(){
  int key = 0;
  for(int i = 2;i<=N;i++){
    if(lp[i]==0){
      lp[i] = i;
      primes.push_back(i);
      M[i]= key++;
    }
    for(int j = 0;j<primes.size() && primes[j]*i<=N && primes[j]<=lp[i];j++)
      lp[primes[j]*i] = primes[j];
  }
}

int DP[107][1<<16];
int best[107][1<<16];
int Next[107][1<<16];
vector<int> nums;
vector<int> res;
vector<int> suffix;
const int inf = 1e9;
int main(){__
  int n;
  criba();
  cin>>n;
  nums.resize(n);
  res.resize(n);
  suffix.resize(n);
  for(auto &c:nums)cin>>c;
  
  suffix[n-1] = nums[n-1]-1;
  for(int i = n-2;i>=0;i--){
    suffix[i] = suffix[i+1]+(nums[i]-1);
  }

  for(int i = 0;i<n;i++){
    for(int j = 0;j<(1<<17);j++){
      DP[i][j] = inf;
    }
  }

  //solve(0,0);
  
  for(int mask = 0;mask<(1<<16);mask++){
    DP[n][mask] = 0;
  }

  vector<int> Msk(53);
  for(int i = 1;i<=53;i++){
    int x = i;
    int nmask = 0;
    while(x>1){
      nmask |= 1<<M[lp[x]];
      x/=lp[x];
    }
    Msk[i]= nmask;
  }
  for(int i = n-1;i>=0;i--){
    for(int mask = 0;mask<(1<<16);mask++){
      int mn = inf;
      for(int j = 1;j<=min(2*nums[i],53);j++){
        int nmask = Msk[j];
        if(nmask & mask)continue;
        int z = abs(nums[i]-j)+DP[i+1][nmask|mask];
        if(z<mn){
          mn = z;
          best[i][mask] = j;
          Next[i][mask] = mask|nmask;
        }
      }
      DP[i][mask] = mn;
    }
  }

  res[0] = best[0][0];
  int last = Next[0][0];
  for(int i = 1;i<n;i++){
    res[i] = best[i][last];
    last = Next[i][last];
  }
  for(int i = 0;i<n;i++){
    cout<<res[i]<<" ";
  }
  cout<<endl;
}
