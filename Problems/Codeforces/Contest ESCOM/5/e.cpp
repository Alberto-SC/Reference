#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(void) {
    ios_base::sync_with_stdio(0);
    ios::sync_with_stdio(false), cin.tie(0);
    ll n;
    cin>>n;
    vector<ll>difs;
    vector<int> nums(1000020);
    for (int i = 0; i < n; i++) 
        cin>>nums[i];
    if (n == 1) {
        cout<<0;
        return 0;
    }
    else if (n == 2) {
        cout<<min(abs(nums[1] - nums[0]),abs(nums[1]+nums[0]));
        return 0;
    }
    ll sum = 0;
    for (int i = 0; i<n - 1; i++) {
        sum += abs(nums[i + 1] - nums[i]);
        difs.push_back(abs(nums[i + 1] + nums[i]) - abs(nums[i + 1] - nums[i]));
    }
    sort(difs.begin(), difs.end());
    if (difs[0] < 0) {
        sum += difs[0];
    }
    if (difs[1] < 0) {
        sum += difs[1];
    }
    cout<<sum<<endl;
}
