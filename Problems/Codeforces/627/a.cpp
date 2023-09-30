#include <bits/stdc++.h>
using namespace std;
int main(){
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        int p=0,im=0;
        for(int i= 0;i<n;i++){
            if(nums[i]&1)im++;
            else p++;
        }
        if(p!=0&&im!=0)cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }   
    return 0;
}