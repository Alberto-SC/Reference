#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,s;
    cin>>n>>s;
    if(s<=n)return cout<<1<<endl,0;
    int x = s/n;
    if(s%n == 0)return cout<<x<<endl,0;
    cout<<x+1<<endl;
    return 0;
}