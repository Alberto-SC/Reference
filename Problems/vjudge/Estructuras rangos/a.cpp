#include <bits/stdc++.h>
using namespace std;
#define print(A)for(auto c:A)cout<<c<<" ";cout<<endl;
typedef long long int lli;
vector<lli> bit;
int n,m;
lli sum(int idx) {
    lli ret = 0;
    for (++idx; idx > 0; idx -= idx & -idx)ret += bit[idx];
    return ret;
}

lli sum(lli l, lli r) {
    return sum(r) - sum(l - 1);
}

void add(int idx, lli delta){
    for (++idx; idx < n; idx += idx & -idx) bit[idx] += delta;
}
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        lli ans  = 0;
        n = 100007;
        vector<int> copy = nums;
        sort(nums.begin(),nums.end());
        for(int i = 0;i<copy.size();i++){
            int index = lower_bound(nums.begin(),nums.end(),copy[i])-nums.begin();
            copy[i] = index;
        }  
        bit.assign(n,0);
        for(int i = 0;i<nums.size();i++){
            ans+=sum(copy[i]);
            add(copy[i]+1,nums[copy[i]]);
        }
        cout<<ans<<endl;
    }
    return 0;
}