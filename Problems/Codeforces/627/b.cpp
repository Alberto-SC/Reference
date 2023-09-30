#include <bits/stdc++.h>
using namespace std;
int main(){
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        bool flag = false;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        for(int i = 0;i<n;i++){
            for(int j = i+2;j<n;j++){
                if(nums[i] == nums[j]){flag = true;break;}
            }
            if(flag)break;
        }
        if(flag)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }   
    return 0;
}