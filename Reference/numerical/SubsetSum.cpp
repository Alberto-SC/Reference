/**
 * Author: David Rydh, Per Austrin
 * Date: 2003-03-16
 * Description: Some aplications of functions of polynomial
*/
// #include "ExtendedPolynomial"
// number of subsets of an array of n elements having sum equal to k for each k from 1 to m
int main() {
  int n, m; cin >> n >> m;
  vector<int> a(m + 1, 0);
  for (int i = 0; i < n; i++) {
    int k; cin >> k; // k >= 1, handle [k = 0] separately
    if (k <= m) a[k]++;
  }
  poly p(m + 1, 0);
  for (int i = 1; i <= m; i++) {
    for (int j = 1; i * j <= m; j++) {
      if (j & 1) p.a[i * j] += mint(a[i]) / j;
      else p.a[i * j] -= mint(a[i]) / j;
    }
  }
  p = p.exp(m + 1);
  for (int i = 1; i <= m; i++) cout << p[i] << ' '; cout << '\n'; // check for m = 0
  return 0;
}

// Calc bell numbers
vector<mint> bell(int n) { // e^(e^x - 1)
  poly p(n + 1);
  mint f = 1;
  for (int i = 0; i <= n; i++) {
    p.a[i] = mint(1) / f;
    f *= i + 1;
  }
  p.a[0] -= 1;
  p = p.exp(n + 1);
  vector<mint> ans(n + 1);
  f = 1;
  for (int i = 0; i <= n; i++) {
    ans[i] = p[i] * f;
    f *= i + 1;
  }
  return ans;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n; cin >> n;
  auto ans = bell(n);
  cout << ans[n] << '\n';
  return 0;
}

//$O((MAXK^2)/32)$ 
//MAXK is the maximum possible sum. 
bitset<MAXK> dp;
dp[0] = 1;
for (int i = 1; i <= n; i++) {
  for (int x = 0; (1<<x) <= m[i]; x++) {
    dp |= (dp << (a[i]*(1<<x)));
    m[i] -= (1<<x);
  }
  dp |= (dp << (a[i]*m[i]));
}


long long kSum(vector<int>& nums, int k) {
  ll sum=0,n=nums.size();
      vector<ll> ans;  
      for(ll i=0;i<nums.size();i++){
          if(nums[i]>0)
              sum+=nums[i]; 
          nums[i]=abs(nums[i]);
    
      }
      ans.push_back(sum);
      priority_queue<pair<ll,ll>> pq;  
      sort(nums.begin(),nums.end()); 
      pq.push({sum-nums[0],0}); 
      while(ans.size()<k){
          auto [sum,ind]=pq.top();
          pq.pop();
          if(ind+1<n){
    
              pq.push({sum+nums[ind]-nums[ind+1],ind+1}); 
              pq.push({sum-nums[ind+1],ind+1});
          }
          ans.push_back(sum);			
      }
      return ans.back();            
  }