#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define print(A)for(auto c:A)cout<<c<<" ";cout<<endl;
vector<int> bit;
int n;
int sum(int idx) {
    int ret = 0;
    for (++idx; idx > 0; idx -= idx & -idx)ret += bit[idx];
    return ret;
}

int sum(int l, int r) {
    return sum(r) - sum(l - 1);
}

void add(int idx, int delta) {
    for (++idx; idx < n+1; idx += idx & -idx) bit[idx] += delta;
}

int main(){
    int p;
    cin>>n>>p;
    vector<int> nums(n);
    bit.resize(n+7);
    for(auto &c:nums)cin>>c;
    vector<int> values = nums;
    sort(values.begin(), values.end());
    values.erase(unique(values.begin(), values.end()), values.end());
    for (int i = 0; i < n; i ++) 
        nums[i] = (int)(lower_bound(values.begin(), values.end(), nums[i]) - values.begin());
    lli inv= 0,mx = -1,idx = -1;
    for(int i = 0;i<n;i++){
        if(i>=p){
            add(nums[i-p],-1);
            inv-= sum(nums[i-p]-1);
        }
        add(nums[i],1);
        inv+= min(i+1,p)-sum(nums[i]);
        // cout<<sum(nums[i])<<"  "<<i<<" "<<inv<<endl;
        if(inv>mx)mx = inv,idx=(i-p)+1;
    }
    if(idx<=0)cout<<1<<" "<<mx<<endl;
    cout<<idx+1<<" "<<mx<<endl;
    // print(bit);
}