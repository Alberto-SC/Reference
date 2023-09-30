#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __                                                                     \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);

const int mod = 998244353;


signed main() {
  __ int T = 1, n;
  vector<int> nums(n);
  for (auto &c : nums)
    cin >> c;

  while (T--) {
    vector<int> nums(6);
    for (auto &c : nums)
      cin >> c;
    int x =
        ((((nums[0] % mod) * (nums[1] % mod)) % mod) * (nums[2] % mod)) % mod;
    int y =
        ((((nums[3] % mod) * (nums[4] % mod)) % mod) * (nums[5] % mod)) % mod;
    x -= y;
    if (x < 0)
      x += mod;
    cout << x << endl;
  }
  return 0;
}
