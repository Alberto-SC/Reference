
#include <bits/stdc++.h>
using namespace std;
int main(){
    int t,n,m;
    cin>>t;
    while(t--){
        cin>>n>>m;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum>m)cout<<m;
        else cout<<sum<<endl;
    }
    return 0;
}