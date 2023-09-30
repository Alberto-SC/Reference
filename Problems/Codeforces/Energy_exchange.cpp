#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef long double ld;

int main(){
    int n,k;
    cin>>n>>k;
    vector<ld>nums(n);
    vector<ld> preffix(n);
    for(auto &c:nums)cin>>c;
    sort(nums.begin(),nums.end());
    preffix[0] = nums[0];
    for(int i = 1;i<n;i++)preffix[i] = preffix[i-1]+nums[i];
    ld l = 0.0,r = 1000.0;
    int reps = 50;
    while(reps--){
        ld m = (l+r)/2.0;
        ld p = 0.0,s = 0.0;
        for(int i = 0;i<n;i++){
            if(isgreater(nums[i],m))
                s+=nums[i]-m;
            else 
                p+=((m-nums[i])*100)/(100.0-k);
        }
        if(p>=s)r = m;
        else l = m;
    }
    cout<<fixed<<setprecision(10);
    cout<<l<<endl;
    return 0;
}