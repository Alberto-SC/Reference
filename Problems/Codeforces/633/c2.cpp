#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main(){
    int t,n;
    cin>>t;
    while(t--){
        int mx = -1;
        cin>>n;
        vector<lli> nums(n);
        for(auto &c:nums)cin>>c;
        for(int i =1;i<n;i++){
            lli dif = nums[i]-nums[i-1];
            if(dif>=0)continue;
            else {
                int k = (int)(log2(-dif)); 
                mx = max(mx,k);
                nums[i]+=-dif;
            }
        }
        if(mx == -1)cout<<0<<endl;
        else cout<<mx+1<<endl;
    }
    return 0;
    
}