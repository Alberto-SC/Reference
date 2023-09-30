#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define x first
#define y second
int main(){
    int n,ng = 0,p = 0,zeros= 0;
    cin>>n;
    vector<int> nums(n);
    for(auto &c:nums)cin>>cn   ;
    for(int i = 0;i<n;i++)
        if(nums[i] >= 0)nums[i] = -nums[i]-1;
    int mn = *min_element(nums.begin(),nums.end());
    if(n&1){
        for(int i = 0;i<n;i++){
            if(nums[i] == mn){
                nums[i] = -nums[i]-1;
                break;
            }
        }
    }
    for(auto c:nums)cout<<c<<" ";
    cout<<endl;
    return 0;
}