#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>a>>n;
    while(a%2==0){
        a/=2;
        cont2++;
    }
    while(a%5 ==0){
        a/=5;
        cont5++;
    }
    if(a>1 && n!= 0){
        cout<<"Precision Error"<<endl;
    }
    else if(n==0){
        cout<<0<<" "<<1<<endl;
    }
    int v = cont2*n;
    int w = cont5*n;
    int m = max(v,w);
    
    cout<<m<<" "<<endl;

    return 0;
}