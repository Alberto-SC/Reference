#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    long long sum = 0;
    for(int i = 0;i<n;i++){
        cin>>nums[i];      
        sum+=nums[i];  
    }
    if(sum&1)cout<<"NO"<<endl;
    else {
        for(int i = n-1;i>=0;i--){
            if(sum-nums[i]>=nums[i])continue;
            else return cout<<"NO"<<endl,0;
        }
        cout<<"YES"<<endl;
    }
    return 0;
}