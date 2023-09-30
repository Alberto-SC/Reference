#include <bits/stdc++.h>
using namespace std;
int main(){
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        bool par = false;
        int i;
        for(i = 0;i<n;i++)if(nums[i]%2 == 0){par = true;break;}
        if(par == true)cout<<1<<endl<<i+1<<endl;
        else {
            if(n>1)cout<<2<<endl<<"1 2"<<endl;
            else cout<<-1<<endl;
        }
    }
    return 0;
}