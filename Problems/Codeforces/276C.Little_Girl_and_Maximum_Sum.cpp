#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main(){
    int n,q,l,r;
    cin>>n>>q;
    vector<lli> nums(n);
    vector<lli> a(n+1);
    for(auto &c:nums)cin>>c;
    for(int i = 0;i<q;i++){
        cin>>l>>r;
        l--,r--;
        a[l]++;
        a[r+1]--;
    }
    sort(nums.rbegin(),nums.rend());
    for(int i =1;i<n+1;i++){
        a[i] = a[i-1]+a[i];
    }
    sort(a.rbegin(),a.rend());
    lli ans = 0;
    for(int i = 0;i<n;i++){
        ans+=a[i]*nums[i];
    }
    cout<<ans<<endl;
    return 0;
}