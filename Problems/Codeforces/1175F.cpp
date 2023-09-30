#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define endl '\n'
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
const int maxn = 300007;
vector<int> hs(maxn);
vector<int> ac(maxn);
vector<int> ach(maxn);
vector<int> nums(maxn);

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
int rand(int a, int b){
	uniform_int_distribution<int> dist(a, b);
	return dist(rng);
}

void init(){
  for(int i  = 1;i<maxn;i++){
    hs[i] = rand(1,1e18);
  }
  for(int i = 1;i<maxn;i++){
    ach[i] = hs[i];
    ach[i] ^= ach[i-1];
  }
}
int ans = 0;
void solve(int l,int r){
  if(r<l)return;
  //cout<<l<<" "<<r<<endl;
  //cout<<endl;
  int mx = 0,id = 0;
  for(int i = l;i<=r;i++){
    if(nums[i]>mx){
      mx = nums[i];
      id = i;
    }
  }
  int x = ach[mx];

  for(int i = max(l,id-(mx+1));i<=id;i++){
    int R = (i+mx)-1;
    if(R>r)break;
    //cout<<i<<" "<<R<<" "<<l<<" "<<r<<" "<<id<<endl;
    int h = ac[R]^(i?ac[i-1]:0);
    if(h==x)ans++;
  }

  solve(l,id-1);
  solve(id+1,r);
}
signed main(){__
  int n;
  cin>>n;
  init();

  for(int i = 0;i<n;i++){
    cin>>nums[i];
    ac[i] = hs[nums[i]];
    ac[i] ^= i?ac[i-1]:0;
  }
  
  solve(0,n-1);
  cout<<ans<<endl;
  return 0;
}
