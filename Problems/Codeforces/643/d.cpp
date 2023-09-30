#include <bits/stdc++.h>
using namespace std;
int main(){ 
    int n,s;
    cin>>n>>s;
    int sum = 0;
    vector<int> nums;
    for(int i = 0;i<n;i++){
        if(i == n-1)nums.push_back(s-sum);
        else {
            sum+=2;
            nums.push_back(2);
        }
    }
    if(nums.back() == 1 ||  nums.back()<=0 )return cout<<"NO"<<endl,0;
    cout<<"YES"<<endl;
    for(auto c:nums)cout<<c<<" ";
    cout<<endl<<1<<endl;
    return 0;
}