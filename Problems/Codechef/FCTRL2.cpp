#include <bits/stdc++.h>
using namespace std;
int  fac[200];
void fact(int n){
    fac[0] = 1;
    fac[1] = 1;
    int m = 1,mult,temp = 0;
    for(int i = 2;i<=n;i++){
        for(int j = 0;j<m;j++){
            mult = fac[j]*i+temp;
            fac[j] = mult%10;
            temp = mult/10;
        }
        while(temp){
            fac[m] = temp%10;
            temp/=10;
            m++;
        }
    }
    for(int i = m-1;i>=0;i--){
        cout<<fac[i];
    }
    cout<<endl;
}
int main(){
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        fact(n);
    }
    return 0;
}