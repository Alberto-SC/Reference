#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(auto &c:nums)cin>>c;
    vector<int> R(n);
    vector<int> L(n);
    for(int i = 0;i<n;){
        int j = i+1;
        while(j<n && nums[j]>nums[j-1]){
            j++;
        }
        int cont = 0;
        for(int k = i;k<j;k++)
            R[k] = (j-i)-cont++;
        i = j;
    }
    for(int i = n-1;i>=0;){
        int j = i-1;
        while(j>=0 && nums[j]<nums[j+1]){
            j--;
        }
        int cont = 0;
        for(int k = i;k>j;k--)
            L[k] = (i-j)-cont++;
        i = j;
    }
    int ans = *max_element(R.begin(),R.end());
    for(int i = 1;i<n-1;i++){
        if(nums[i+1]>nums[i-1])
            ans = max(ans,L[i-1]+R[i+1]);
        
    }
    cout<<ans<<endl;
    

    return 0;
}