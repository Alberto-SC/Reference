#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
typedef long double ld;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

vector<ld> nums;
ld l;
ld func(ld x){
    ld t1 = 0.0;
    ld v = 1.0;
    ld d = 0.0;
    for(int i = 0;i<nums.size();i++){
        if(nums[i]>x){
            t1+= (x-d)/v;
            v++;
            break;
        }
        else{
            t1+= (nums[i]-d)/v;
            v+=1;
            d = nums[i];
        }
    }
    if(x>nums.back())
        t1+= (x-d)/v;
    ld t2 = 0;
    d = l;
    v = 1;
    for(int i = nums.size()-1;i>=0;i--){
        if(nums[i]<x){
            t2+= (d-x)/v;
            v++;
            break;
        }
        else{
            t2+= (d-nums[i])/v;
            v+=1;
            d = nums[i];
        }
    }
    if(x<nums[0])
        t2+= (d-x)/v;
    // cout<<fabs(t1-t2)<<" ";
    return fabs(t1-t2);
}
ld gettime(ld x){
    ld t = 0;
    ld v = 1;
    ld d = 0;
    for(int i = 0;i<nums.size();i++){
        if(nums[i]>x){
            t+= (x-d)/v;
            v++;
            break;
        }
        else{
            t+= (nums[i]-d)/v;
            v+=1;
            d = nums[i];
        }
    }
    if(x>nums.back())
        t+= (x-d)/v;
    return t;
}

ld ts(ld start, ld end){
    ld l = start, r = end;
    for(int i=0; i<200; i++) {
      ld l1 = (l*2+r)/3;
      ld l2 = (l+2*r)/3;
    //   cout<<l1<<" "<<l2<<endl;
      if(func(l1) < func(l2)) r = l2; else l = l1;
        // cout<<endl;
    }
     ld x = l;
    return l;
}

int main(){__
    int t = 1,n;
    cin>>t;
    while(t--){
        cin>>n>>l;
        nums.resize(n);
        for(auto &c:nums)cin>>c;
        cout<<fixed<<setprecision(10);
        cout<<gettime(ts(0.0,l*1.0))<<endl; 
    }
    return 0;
}

