#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    if(k>n)return cout<<"IMPOSSIBLE"<<endl,0;
    if(k == n)return cout<<string(n,'a')<<endl,0;
    if(k<3)return cout<<"IMPOSSIBLE"<<endl,0;
    int nx = k-min(n,3);
    string ans = string(nx,'x');
    string abc = "abc";
    for(int i = 0;i<ceil(n/3.0);i++)ans+=abc;
    cout<<ans.substr(0,n)<<endl;
    
    return 0;
}