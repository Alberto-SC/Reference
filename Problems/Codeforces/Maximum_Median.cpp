#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main(){
    lli n,k;
    cin>>n>>k;
    vector<lli> nums(n);
    for(auto &c:nums)cin>>c;
    sort(nums.begin(),nums.end());
    vector<lli> c;
    for(lli i = (n/2)+1;i<n;i++)
        c.push_back(nums[i]-nums[i-1]);
    lli ans = 0,cont = 1;
    int i;
    for(i = 0;i<c.size();i++){
        if(k-cont*c[i]>=0){
            k -=cont*c[i];
            cont++;
            nums[n/2]+=c[i];
        }
        else break;
    }
    nums[n/2]+=k/cont;
    cout<<nums[n/2]<<endl;
    return 0;
}