#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main(){
    int n;
    cin>>n;
    string a,b;
    cin>>a>>b;
    lli ans = 0;
    lli ones = 0,zeros = 0,one2 = 0,zero2= 0;
    for(int i = 0;i<n;i++)a[i] == '0'?zeros++:ones++;
    for(int i = 0;i<n;i++){
        if(b[i] == '0'){
            if(a[i] == '0' ){
                ans+=ones;
                zero2++;
            }
            else ans+=zeros,one2++;
        }
    }
    cout<<ans-(one2*zero2)<<endl;
    return 0;
}