#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,ans,t;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> nums(n);
        ans = 0;
        for(int i = 0;i<n;i++){
            cin>>nums[i];
            if(nums[i] == 0)ans++;
        }

        int suma = accumulate(nums.begin(),nums.end(),0);
        if(ans == 0){
            if(suma== 0)ans++;
        }
        else {
            if(suma+ans == 0)ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}