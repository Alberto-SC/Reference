#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define int long long int
#define endl '\n'
#define pb push_back
#define pi pair<int, int>
#define pii pair<int, pi>
#define fir first
#define sec second
#define MAXN 1010
#define mod 1000000007

struct modint
{
  int val;
  modint(int v = 0) { val = v % mod; }
  int pow(int y)
  {
    modint x = val;
    modint z = 1;
    while (y)
    {
      if (y & 1)
        z *= x;
      x *= x;
      y >>= 1;
    }
    return z.val;
  }
  int inv() { return pow(mod - 2); }
  void operator=(int o) { val = o % mod; }
  void operator=(modint o) { val = o.val % mod; }
  void operator+=(modint o) { *this = *this + o; }
  void operator-=(modint o) { *this = *this - o; }
  void operator*=(modint o) { *this = *this * o; }
  void operator/=(modint o) { *this = *this / o; }
  bool operator==(modint o) { return val == o.val; }
  bool operator!=(modint o) { return val != o.val; }
  int operator*(modint o) { return ((val * o.val) % mod); }
  int operator/(modint o) { return (val * o.inv()) % mod; }
  int operator+(modint o) { return (val + o.val) % mod; }
  int operator-(modint o) { return (val - o.val + mod) % mod; }
};

int dp[60][2][2][2][2][2][2];
pi v[3];

pi go(int i, int j, int a, int b, int bit, int pos)
{
  int l = (a & (1ll << pos)) ? 1 : 0;
  int r = (b & (1ll << pos)) ? 1 : 0;
  int ii = 0, jj = 0;
  if (i || (bit > l))
    ii = 1;
  if (j || (bit < r))
    jj = 1;
  if (!i && (l > bit))
    ii = -1;
  if (!j && (bit > r))
    jj = -1;
  cout<<l<<" "<<r<<" "<<a<<" "<<b<<" "<<bit<<" "<<pos<<" "<<ii<<" "<<jj<<endl;
  return {ii, jj};
}
int solve(int b, int i, int j, int k, int l, int m, int n)
{
  if (b < 0)
    return (i && j && k && l && m && n) ? 1 : 0;
  if (dp[b][i][j][k][l][m][n] != -1)
    return dp[b][i][j][k][l][m][n];
  modint ans = 0;
  vector<vector<int>> nxt = {{0, 0, 0}, {1, 0, 1}, {1, 1, 0}, {0, 1, 1}};
  for (auto const &r : nxt)
  {
    pi aa = go(i, j, v[0].fir, v[0].sec, r[0], b);
    pi bb = go(k, l, v[1].fir, v[1].sec, r[1], b);
    pi cc = go(m, n, v[2].fir, v[2].sec, r[2], b);
    // if (aa.fir != -1 && aa.sec != -1 && bb.fir != -1 && bb.sec != -1 && cc.fir != -1 && cc.sec != -1)
    //   ans += solve(b - 1, aa.fir, aa.sec, bb.fir, bb.sec, cc.fir, cc.sec);
  }
  return dp[b][i][j][k][l][m][n] = ans.val;
}
signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  modint q = 1;
  for (int i = 0; i < 3; i++)
  {
    cin >> v[i].fir >> v[i].sec;
    q *= (v[i].sec - v[i].fir + 1);
    v[i].fir--, v[i].sec++;
  }
  memset(dp, -1, sizeof(dp));
  modint p = solve(4, 0, 0, 0, 0, 0, 0);
  p = q - p;
  modint ans = p / q;
  cout << ans.val << endl;
  return 0;
}