#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
int main(){
    int n;
    int nums[6] ;
    cin>>nums[0]>>nums[1];
    for(int i = 2 ;i<6;i++)
        nums[i] = nums[i-1]-nums[i-2];
    cin>>n;
    cout<<(nums[(n-1)%6]%mod+mod)%mod;
    return 0;
}