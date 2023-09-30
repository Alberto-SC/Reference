#include <bits/stdc++.h>
using namespace std;
int main(){
    int a,b,c,n,t;
    cin>>t;
    while(t--){
        cin>>a>>b>>c>>n;
        int total = a+b+c+n;
        if(total%3 == 0 && a<=(total/3) && b<=(total/3) && c<=(total/3))cout<<"YES"<<endl;
        else cout<<"NO"<<endl;   
    }
    return 0;
}