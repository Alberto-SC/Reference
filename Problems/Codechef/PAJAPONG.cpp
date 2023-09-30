#include <bits/stdc++.h>
using namespace std;
int main(){
    int x,y,k,t;
    cin>>t;
    string serv[] = {"Chef","Paja"};
    int s = 0;
    while(t--){
        cin>>x>>y>>k;
        if((x+y)%2==0)cout<<"Chef";
        else cout<<"Paja";
        cout<<"\n";
    }
    return 0;
}