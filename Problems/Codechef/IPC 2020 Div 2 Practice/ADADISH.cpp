#include <bits/stdc++.h>
using namespace std;
int main(){
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        int ans = 10000;
        for(int i = 0;i<1<<n;i++){
            int aux = i;
            int sumA = 0,sumB = 0;
            for(int k = 0;k<n;k++){
                if((aux>>k)&1)
                    sumA+=nums[k];
                
                else sumB+=nums[k];
            }
            ans = min(ans,max(sumA,sumB));
        }
        cout<<ans<<endl;
    }
    return 0;
}