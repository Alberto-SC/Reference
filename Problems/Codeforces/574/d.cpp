#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i = 0;i<n;i++){
        cin>>nums[i];
    }
    long long ans = 0;
    for(int i = 0;i<n;i++){
        double  log = log10(nums[i]);
        int num= ceil(log);
        cout<<num<<endl;
        for(int j = 0;j<=num;j++){
            cout<<nums[i]<<"  "<<nums[i]%10<<"   "<<nums[i]%10*(pow(10,(j*2)))<<"   "<<nums[i]%10*(pow(10,(j*2)+1))<<endl;
            ans +=nums[i]%10*(pow(10,(j*2)))*n;
            ans+= nums[i]%10*(pow(10,(j*2)+1))*n;       
            nums[i]/=10;
        }
    }
    cout<<ans<<endl;
}