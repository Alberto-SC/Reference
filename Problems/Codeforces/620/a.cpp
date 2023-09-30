#include <bits/stdc++.h>
using namespace std;
int main(){
    int s,e,a,b,t;
    cin>>t;
    cout<<fixed<<setprecision(0);
    while(t--){
    cin>>s>>e>>a>>b;
        if(ceil((e-s)/((a+b)*1.0)) ==floor((e-s)/((a+b)*1.0)) )cout<<ceil((e-s)/((a+b)*1.0))<<endl;
        else cout<<-1<<endl;
    }
    return  0;
}