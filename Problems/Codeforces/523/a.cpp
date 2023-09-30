#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,s;
    cin>>n>>s;
    int ans = s/n;
    if(s%n==0)cout<<ans<<endl;
    else
        cout<<ans+1<<endl;
    return 0;
}