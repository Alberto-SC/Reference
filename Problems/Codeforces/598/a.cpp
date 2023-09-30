#include <bits/stdc++.h>
using namespace std;
int main(){
    int t,a,b,n,s;
    cin>>t;
    while(t--){
        cin>>a>>b>>n>>s;
        if((a>= s/n && s%n == 0)||(a>= s/n && s%n <= b) || s<=b)cout<<"YES"<<endl;
        else if(a< s/n && s<=((a*n)+b))cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}