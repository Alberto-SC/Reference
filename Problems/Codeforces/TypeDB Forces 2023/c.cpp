#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
	*this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
// debug & operator << (debug & dd, P p) { dd << "(" << p.x << ", " << p.y << ")"; return dd; }
 

signed main(){__
    int T = 1,n,s;
    cin>>T;
    while(T--){
        cin>>n>>s;
        vector<int> nums(n);
        vector<int> x(n);
        vector<int> y(n);
        for(int i = 0;i<n;i++){
            cin>>nums[i];
            if(nums[i]<=s){
                x[i] = nums[i];
                y[i] = 0;
            }
            else{
                x[i] = s;
                y[i] = nums[i]-s;
            }
        }

        vector<int> dp[2];
        dp[0].resize(n);
        dp[1].resize(n);

        dp[0][1] = nums[0]*x[1];
        dp[1][1] = nums[0]*y[1];

        for(int i = 2;i<n-1;i++){
            dp[0][i] = min(dp[0][i-1]+(x[i]*y[i-1]),dp[1][i-1]+(x[i]*x[i-1]));
            dp[1][i] = min(dp[0][i-1]+(y[i]*y[i-1]),dp[1][i-1]+(y[i]*x[i-1]));
        }
        // cout<<dp[0][n-2]<<" "<<dp[1][n-2]<<endl;
        int ans1 = dp[0][n-2]+(y[n-2]*nums.back());
        int ans2 = dp[1][n-2]+(x[n-2]*nums.back());
        cout<<min(ans1,ans2)<<endl;
    }
    return 0;
}