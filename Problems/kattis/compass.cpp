#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,r;
    cin>>n>>r;
    if(r<n){
        if(((360-n)+r)<(n-r))
            cout<<(360-n)+r;
        else  

            n-r==180?cout<<180:cout<<"-"<<n-r;
    } 
    else {
        if(((360-r)+n)<(r-n)){
            if((360-r)+n==180)cout<<180;
            else 
                cout<<"-"<<(360-r)+n;
        }
        else 
            cout<<r-n;
    }
    return 0;
}