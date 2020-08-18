#include <bits/stdc++.h>
using namespace std;
// Longest increasing secuence in o(nlogn)
vector<int> d;
int main() {
    int ans, n;
    cin>>n;
    vector<int> nums(n);
    for(auto &c:nums)cin>>c;
    for (int i = 0; i<n;i++) {
        auto it = upper_bound(d.begin(), d.end(), nums[i]);
        if (it == d.end()) d.push_back(nums[i]);
        else *it = nums[i];
    }
    cout<<"LIS ="<<d.size<<endl;
    return 0;
}
