#include <bits/stdc++.h>
using namespace std;
vector<int> nums;
int n,k;
typedef long double ld;
bool check(ld x){
    int n = nums.size();
    int c= 0;
    for(int i = 0;i<n;i++){
        c+=floor(nums[i]/x);
    }
    if(c>=k)return true;
    return false;
}
int main(){
    cin>>n>>k;
    nums.resize(n);
    for(auto &c:nums)cin>>c;
    ld l = 0,r = 10000007;
    int times = 100;
    while(times){
        ld mid = (l+r)/2;
        if(check(mid))
            l = mid;
        else 
            r = mid;
        times--;
    }
    cout<<fixed<<setprecision(8);
    cout<<l<<endl;
    return 0;
}