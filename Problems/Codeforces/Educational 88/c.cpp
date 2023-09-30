#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main(){
    int t;
    double a,b,d;
    cin>>t;
    while(t--){
        cin>>a>>b>>d;
        vector<double> diff;
        double sum = (a+b+a);
        diff.push_back(sum/3);
        for(int i = 5;i<100;i+=2){
            diff.push_back((sum+b+a)/i);
            sum+=b+a;
        }
        lli l = 1,r = 100000000;
        cout<<fixed<<setprecision(5);
        double two = (a+b)/2.0;
        // cout<<(a+b)/2.0<<endl;
        // cout<<(a+b+a+b+a)/5.0<<endl;
        if((a+b)/2 == d || isgreater(two,d)){cout<<2<<endl;continue;}
        else if(a ==d){cout<<1<<endl;continue;}
        while(l<r){
            lli mid = (l+r+1)>>1;
            double sum = a+((mid-1)*a)+((mid-1)*b);
            double y = sum/((mid*2)-1);
            // cout<<mid<<" "<<sum<<" "<<y<<endl;
            // if(isgreater(y,d) && isless(y,d)){r = mid-1;break;}
            if(isgreater(y,d))l = mid;
            else r = mid-1;
        }
        double sum1 = a+((r-1)*a)+((r-1)*b);
        double y1 = sum1/((r*2)-1);
        double sum2 = a+((r)*a)+((r)*b);
        double y2 = sum2/(((r+1)*2)-1);
        // cout<<y1<<" "<<y2<<endl;
        if(isgreater(fabs(d-y1),fabs(d-y2)))cout<<((r+1)*2)-1<<endl;
        else cout<<(r*2)-1<<endl;

        // cout<<(r*2)-1<<endl;
    }
    
    return 0;
}