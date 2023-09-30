#include <bits/stdc++.h>
using namespace std;
int main(){
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> nums(n+1);
        vector<int> dp(n+1,1);
        for(int i = 0;i<n;i++)cin>>nums[i+1];
        for(int i = n;i>=1;i--){
            int x = i;
            int cont = 2;
            int mx = -1000;
            while(x<=n){
                x=i*cont;
                if(x>n)break;
                if(nums[x]>nums[i])
                mx = max(dp[x],mx);
                cont++;
            }
            if(mx!= -1000)
            dp[i] += mx;
        }
        cout<<*max_element(dp.begin(),dp.end())<<endl;
    }
    return 0;
}