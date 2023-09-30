#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(auto &c:nums)cin>>c;
    int l = 0,r = 0,cont = 0,j = 0;
    for(int i = 1;i<n;i = j){
        if(nums[j]<nums[j-1])cont++,l = i;
        while(nums[j]<nums[j-1]){j++;}
        r = j;
        if(j == i)j++;
    }
    if(cont > 1)return cout<<"no"<<endl,0;
    cout<<"yes"<<endl;
    if(cont == 0)return cout<<"1 1"<<endl,0;
    cout<<l<<" "<<r-1<<endl;
    return 0;
}