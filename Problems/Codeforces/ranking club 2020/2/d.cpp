#include <bits/stdc++.h>
using namespace std;
int main(){
    int t,n,m;
    cin>>t;
    while(t--){
        cin>>n>>m;
        if(n%2==0&&m%2==0) 
            cout<<"abdullah"<<endl;
        else
            cout<<"hasan"<<endl;
    }
    return 0;
}