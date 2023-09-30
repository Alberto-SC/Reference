#include <bits/stdc++.h>
using namespace std;
int main(){ 
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);  
    int n,k,ti,ans = 0;
    cin>>n>>k;
    for(int i = 0;i<n;i++){
        cin>>ti;
        if(ti%k== 0)ans++;
    }
    cout<<ans;
    return 0;
}