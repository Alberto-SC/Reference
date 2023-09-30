#include <bits/stdc++.h>
using namespace std;
int main(){
    int t,n,m;
    cin>>t;
    while(t--){
        cin>>n>>m;
        if(n == 1 || m == 1  ||(m ==2 && n == 2))cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}