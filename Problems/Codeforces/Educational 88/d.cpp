#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

const int INF = 1000000000;
int main(){
    int n;
    cin>>n;
	vector<int> nums(n);
    for(auto &c:nums)cin>>c;
	lli ans = 0;
	for(int mx = 0;mx<31;mx++){
		lli cur = 0;
		lli best = 0;
		for(int i = 0;i<n;i++){
			int val = (nums[i] > mx ? -INF : nums[i]);
			cur += val;
			best = min(best, cur);
			ans = max(ans, (cur - best) - mx);
		}
	}
    cout<<ans<<endl;
    return 0;
}