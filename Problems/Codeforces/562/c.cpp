#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<int> nums(n);
    for(int i = 0;i<n;i++)
        cin>>nums[i];
    int max_change = 0;
    for(int i = 0;i<n-1;i++){
        int besto = 0;
        if(nums[i]>nums[i+1]){
            if(i != 0)
                besto = min(m-nums[i]+nums[i-1],nums[i]-nums[i+1]);
            else 
                besto = min(m-nums[i],nums[i]-nums[i+1]);
        }
        max_change = max(max_change,besto);
    }
    cout<<max_change<<endl;
    return 0;
}