#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
vector<ld> nums;

bool check(ld m){
    ld first = nums[0]+(2*m);
    int idxl = lower_bound(nums.begin(),nums.end(),first+0.0000001)-nums.begin();
    ld last = nums.back()-(2*m);
    int idxr = lower_bound(nums.begin(),nums.end(),last-0.0000001)-nums.begin();
    idxr--;
    if(idxr<=idxl)return true;
    ld distance = nums[idxr]-nums[idxl];
    if(distance <= 2*m)return true;
    return false;
}

void print(ld m){
    ld first = nums[0]+(2*m);
    cout<<first-m<<" ";
    ld last = nums.back()-(2*m);
    int idxl = lower_bound(nums.begin(),nums.end(),first+0.000001)-nums.begin();
    int idxr = lower_bound(nums.begin(),nums.end(),last-0.000001)-nums.begin();
    idxr--;
    if(idxr<idxl)idxr++,idxl--;
    if(idxr ==idxl)cout<<nums[idxl]<<" ";
    else 
        cout<<((nums[idxr]-nums[idxl])/2.0)+nums[idxl]<<" ";
    cout<<last+m<<endl;
}

int main(){
    int n;
    cin>>n;
    nums.resize(n);
    for(auto &c:nums)cin>>c;
    sort(nums.begin(),nums.end());
    ld l = 0.0,r = 1000000000.0;
    int times = 100;
    while(times--){
        ld m = (l+r)/2.0;
        if(check(m))
            r = m;
        else l = m;
    }
    cout<<fixed<<setprecision(6);
    cout<<r<<endl;
    print(r);
    
    return 0;
}