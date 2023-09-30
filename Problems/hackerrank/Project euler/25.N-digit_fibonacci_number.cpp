#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
int main(){
    int t,n;
    cin>>t;
    ld r5 = sqrt(5);
    ld phi = (1+r5)/2;
    while(t--){
        cin>>n;
        if(n==1){
            cout<<1<<endl;
            continue;
        }
        for(int i = 2;i<=1000000;i++){
            ld x = (i*log10(phi))-log10(r5);
            int digits = floor(x);
            if(digits+1==n){
                cout<<i<<endl;
                break;
            }
        }
    }
}
