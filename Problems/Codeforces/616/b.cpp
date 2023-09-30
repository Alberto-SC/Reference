#include <bits/stdc++.h>
using namespace std;
int main(){
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        int p = -1, s = n;
        for(int i = 0;i<n;i++){
            if(nums[i]<i)break;
            p = i;
        }
        for(int i = n-1;i>=0;i--){
            if(nums[i]<(n-1)-i)break;
            s = i;
        }
        s<=p?cout<<"YES"<<endl:cout<<"NO"<<endl;
    }
    return 0;
}