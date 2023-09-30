#include <bits/stdc++.h>
using namespace std;
int main(){
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        int mind = 1000000007;
        vector<int> nums(n);
        for(int i = 0;i<n;i++){
            cin>>nums[i];
        }
        sort(nums.begin(),nums.end());
        for(int i = 1;i<n;i++){
            mind = min(nums[i]-nums[i-1],mind);
        }
        cout<<mind<<"\n";
    }
    return 0;
}