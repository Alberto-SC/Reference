#include <bits/stdc++.h>
using namespace std;
int main() {
    int t,n;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        sort(nums.begin(), nums.end());
        int ans = 0, cur = 0;
        for (int i = 0; i < n; i++) {
            if (++cur == nums[i]) {
                ans++;
                cur = 0;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}