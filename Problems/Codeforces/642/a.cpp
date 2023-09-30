#include <bits/stdc++.h>
using namespace std;
int main(){
    int t,n,m;
    cin>>t;
    while(t--){
        cin>>n>>m;
        if(n == 1)cout<<0<<endl;
        else if(n>2)cout<<m*2<<endl;
        else cout<<m<<endl;

    }
    return 0;
}