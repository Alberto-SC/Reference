#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main(){
    string s;
    vector<lli> nums;
    lli x;
    while(cin>>x){
        nums.push_back(x);
    }
    for(int i= 25;i<nums.size();i++){
        bool flag = false;
        for(int j = i-1;j>=i-25;j--){
            for(int k = i-1;k>=i-25;k--){
                if(j ==k)continue;
                if(nums[j]+nums[k]==nums[i]){
                    flag = true;
                    break;
                }
            }
            if(flag)break;
        }
        if(!flag){cout<<nums[i]<<endl;break;}
    }
    return 0;
}