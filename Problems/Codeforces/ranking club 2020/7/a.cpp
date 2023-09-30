#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
lli N = 200007;
vector<lli> bit(N);
lli sum(lli idx) {
    lli ret = 0;
    for (++idx; idx > 0; idx -= idx & -idx)ret += bit[idx];
    return ret;
}

lli sum(lli l, lli r) {
    return sum(r) - sum(l - 1);
}

void add(lli idx, lli delta) {
    for (++idx; idx <= N; idx += idx & -idx) bit[idx] += delta;
}
int main(){
    lli n;
    cin>>n;
    vector<lli> nums(n);
    for(auto &c:nums)cin>>c,c--;
    lli ans = 0;
    vector<vector<lli>> s(N);
    for(lli i=0;i<n; i++){
        if(nums[i] < N)
            s[nums[i]].push_back(i);
        add(i, 1);
    }
    
    for(lli i=0;i<n;i++){
        ans += sum(min(N-1,nums[i]));
        for(auto x : s[i])
            add(x, -1);
    }
        
    for(lli i=0;i<n;i++){
        if(i <= nums[i])
            ans--;
    }
    
	cout<<ans/2<< endl;
    return 0;
}