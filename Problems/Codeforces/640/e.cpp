#include <bits/stdc++.h>
using namespace std;
int main(){
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        vector<int> b(8007);
        for(int i = 0;i<n;i++){
            int ac = nums[i];
            for(int j = i+1;j<n;j++){
                ac+=nums[j];
                if(ac>8000)break;
                b[ac]++;
            }
        }
        int ans = 0;
        for(int i = 0;i<n;i++)if(b[nums[i]])ans++;
        cout<<ans<<endl;
    }
    return 0;
}