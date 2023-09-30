#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main(){
    lli n,a,b;
    cin>>n>>a>>b;
    vector<lli> nums(n);
    for(auto &c:nums)cin>>c;
    for(int i = 0;i<n;i++){
        int mx = (nums[i]*a)/b;
        int l = 0,r = nums[i];
        while(l<r){
            int m = (l+r)>>1;
            if((m*a)/b == mx)
                r = m;
            else l = m+1;
        }
        cout<<nums[i]-l<<" ";
    }
    cout<<endl;
    return 0;
}