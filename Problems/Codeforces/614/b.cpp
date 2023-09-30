#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    double ans = 0;
    cout<<fixed<<setprecision(6);
    if(n == 1)return cout<<1.00000000<<endl,0;
    for(int i = n;i>1;i--){
        int x = i-1;
        // cout<<i/(n*1.0)<<"  "<<(x/(n*1.0))<<"  "<<1/((n-x)*1.0)<<endl;
        if(i/(n*1.0)< (x/(n*1.0))+ 1/((n-x)*1.0)){
            ans+= 1/((n-x)*1.0);
            if(i == 2)ans+=(x/(n*1.0));
        }
        else {
            ans+=(i/(n*1.0));
            break;
        }
    }
    cout<<ans<<endl;
    return 0;
}