#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<int> nums(n);
    for(auto &c:nums)cin>>c;
    for(int i = 0;i<n;i++){
        cout<<nums[i]<<" ";    
    }
    cout<<endl;
    for(int i = 0;i<n;i++){
        cout<<nums[i]*2<<" ";
    }
    cout<<endl;
    return 0;

}
