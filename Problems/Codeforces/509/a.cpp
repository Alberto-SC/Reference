#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,mx = -100,mn = 1000000007;
    cin>>n;
    vector<int> nums(n);
    for(auto &x:nums)cin>>x;
    for(int i = 0;i<n;i++){
        mn = min(mn,nums[i]);
        mx = max(mx,nums[i]);
    }
    cout<<((mx-mn)+1)-n<<endl;

    return 0;
}