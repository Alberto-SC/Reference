#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<double> nums(n);
    for(auto &c:nums)cin>>c;
    double c = 4.0/5.0;
    double accumulate = 0;
    double ans = 0;
    double aux = 1;
    for(int i = 0;i<n;i++){
        ans+=nums[i]*aux;
        aux*=c;
    }
    cout<<fixed<<setprecision(10);
    cout<<ans/5.0<<endl;
    for(int i = 0;i<n;i++){
        ans = 0;
        aux = 1;
        for(int j = 0;j<n;j++){
            if(j == i)continue;
            ans+=nums[j]*aux;
            aux*=c;
        }
        ans/=5.0;
        accumulate+=ans;
    }
    cout<<accumulate/(n*1.0)<<endl;
    return 0;
}