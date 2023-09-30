#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<int> nums(n);
    vector<int> bills(m);
    for(auto &c:nums)cin>>c;
    for(auto &c:bills)cin>>c;
    int i = 0,j = 0,ans = 0;
    while(i<n && j<m){
        if(bills[j]>= nums[i]){ans++;j++;i++;}
        else i++;
    }
    cout<<ans<<endl;
    return 0;
}