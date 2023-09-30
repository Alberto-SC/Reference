#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,v;
    cin>>n>>v;
    if(v>=n-1)return cout<<n-1<<endl,0;
    int ans = 0;
    for(int i = 0;i<n-v;i++){
        if(i == 0)
        ans+=v*(i+1);
        else ans+=(i+1);
    }
    cout<<ans<<endl;
    return 0;
}