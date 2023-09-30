#include <bits/stdc++.h>
using namespace std;
int main(){
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> nums(n);
        if((n/2)&1)cout<<"NO"<<endl;
        else {
            cout<<"YES"<<endl;
            nums[0] = 2;
            for(int i= 1;i<n/2;i++){
                nums[i] =nums[i-1]+2;
            }
            nums[n/2]= 1;
            for(int i = (n/2)+1;i<n-1;i++){
                nums[i] = nums[i-1]+2;
            }
            nums[n-1] = nums[n-2]+2+(n/2);
            for(auto c:nums)cout<<c<<" ";
             cout<<endl;
        }
    }
    return 0;
}