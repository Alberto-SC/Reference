#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
int main(){
    int n;
    cin>>n;
    vector<ld> nums(n);
    for(auto &c:nums)cin>>c;
    for(auto &c:nums)c = log(c);
    ld avg = accumulate(nums.begin(),nums.end(),0.0);
    avg/=n;
    ld var;
    ld sum2 = 0.0;
    for(int i = 0;i<n;i++){
        sum2+=(nums[i]-avg)*(nums[i]-avg);
    }
    var = sum2/(n-1);
    ld desv = sqrt(var);
    ld logvs = avg-(2*desv);
    ld logs = avg-desv;
    ld logm = avg;
    ld logl = avg+desv;
    ld logvl = avg+(2*desv);

    ld vs = exp(logvs);
    ld s = exp(logs);
    ld m = exp(logm);
    ld l = exp(logl);
    ld vl = exp(logvl);
    cout<<fixed<<setprecision(2);
    cout<<vs<<endl<<s<<endl<<m<<endl<<l<<endl<<vl<<endl;
    return 0;
}