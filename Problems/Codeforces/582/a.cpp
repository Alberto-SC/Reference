#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,im = 0,p = 0;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
        if(nums[i]&1)im++;
        else p++;
    }
    if(p>=im)cout<<im;
    else cout<<p;
    return 0;
}