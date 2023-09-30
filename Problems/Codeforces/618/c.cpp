#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,ai = 0;
    cin>>n;
    vector<int> nums(n);
    for(auto &c:nums)cin>>c;
    for(int i = 30;i>=0;i--){
        int count = 0;
        for(int j = 0;j<n;j++)
            if((nums[j]>>i)&1)count++,ai = j;
        if(count == 1)break;
    }
    cout<<nums[ai]<<" ";
    for(int i = 0;i<n;i++)
        if(i!=ai)cout<<nums[i]<<" ";
    
    return 0;
}