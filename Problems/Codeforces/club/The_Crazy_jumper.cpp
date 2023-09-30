#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5+7;
int n;
vector<int> last(MAXN);
vector<int> dp(MAXN);
int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
	int t;
    cin>>t;
	while (t-- != 0) {
        cin>>n;
        vector<int> nums(n);
        for(auto &x:nums)cin>>x;
        last.assign(MAXN,-1);
		last[nums[0]] = 0;
		for (int i = 1; i < n; i++) {
			dp[i] = dp[i -1] + 1;
			if (last[nums[i]] != -1)
				dp[i] = min(dp[i], dp[last[nums[i]]] + 1);
			last[nums[i]] = i;
		}
        cout<<dp[n-1]<<endl;
	}
	return 0;
}