#include <bits/stdc++.h>
typedef long long int lli;
using namespace std;

int main(){
    freopen("key.in","r",stdin);
    freopen("key.out","w",stdout);
    lli n,m;
    cin>>n>>m;
    vector<lli> nums(n);
    for(auto &c:nums)cin>>c;
    sort(nums.begin(),nums.end());
    lli s = 1;
    int i = 0;
    while(m){
        if(i == n || s<nums[i]){
            cout<<s<<" ";
            s*=2;
            m--;
        }
        else s+=nums[i++];
    }
    cout<<endl;
    return 0;
}