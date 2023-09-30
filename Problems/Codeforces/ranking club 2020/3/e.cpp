#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    vector<int> b(1001);
    for(auto &c:nums)cin>>c;
    for(int i = 0;i<n;i++){
        b[nums[i]]++;
    }
    int count = 0,ans= 0;
    bool flag = true;
    while(flag){
        for(int i = 0;i<=1000;i++){
            if(b[i]>=1){count++;b[i]--;}
        }
        if(count>1)ans+=count-1,count = 0;
        else flag = false;
    }
    cout<<ans<<endl;
    return 0;
}