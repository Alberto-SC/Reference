#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,h,m;
    cin>>n;
    map<pair<int,int>,int> mp;
    for(int i = 0;i<n;i++){
        cin>>h>>m;
        mp[{h,m}]++;
    }
    int ans  = -1;
    for(auto c:mp){
        ans = max(ans,c.second);
    }
    cout<<ans<<endl;
    return 0;
}